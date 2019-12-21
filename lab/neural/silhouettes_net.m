dataURL = 'https://people.cs.umass.edu/~marlin/data/caltech101_silhouettes_28.mat';
filename = 'caltech101_silhouettes_28.mat';
outfilename = websave(filename, dataURL);
data = load(outfilename);

encodedY = transpose(encodeOneHot(data.Y));

trainFcn= 'traingdx';
epochs = 1000;
max_fail = 6;
min_grad = 1e-5;

hiddenTransferFcn = 'logsig';
outputTransferFcns = ["logsig", "softmax"];
performFcns = ["mse", "crossentropy"];
divideFcn = 'dividerand';
trainRatios = [0.8, 0.4, 0.1];
valRatios = [0.1, 0.2, 0.1];
testRatios = [0.1, 0.4, 0.8];


% nHiddenUnits = 50;
% seed = 5;
% trainRatio = 0.34;
% valRatio = 0.33;
% testRatio = 0.33;
% bestAccuracyLrMc = 0;
% bestLr = 0;
% bestMc = 0;
% for lr = [0.1 0.01 0.001] % default: 0.01
%     for mc = [0.9 0.09 0.009] % default: 0.9
%         sumAccuracy = 0;
%         for outputTransferFcn_performFcn = {{'logsig', 'mse'}; {'softmax', 'crossentropy'}}
%             outputTransferFcn = outputTransferFcn_performFcn{1}{1};
%             performFcn = outputTransferFcn_performFcn{1}{2};
%        net = createNet(seed, nHiddenUnits, hiddenTransferFcn,...
%                     outputTransferFcn, performFcn, trainRatio, valRatio, testRatio, divideFcn, trainFcn, epochs, max_fail,...
%                     min_grad, mc, lr);
%             [net,tr,Y,E] = train(net, transpose(data.X), encodedY);
%             newAccuracy = getAccuracy(Y(:,tr.testInd), encodedY(:,tr.testInd));
%             sumAccuracy = sumAccuracy + newAccuracy;
%         end
%         meanAccuracy = sumAccuracy/2;
%         if meanAccuracy > bestAccuracyLrMc
%             bestAccuracyLrMc = meanAccuracy;
%             bestLr = lr;
%             bestMc = mc;
%         end 
%     end
% end
% bestAccuracyLrMc
% bestLr
% bestMc
% return;
lr = 0.1;
mc = 0.9;



varNames = ["outputTransferFnc", "hiddenTansferFnc" "performFnc", "nHiddenUnits", "trainRatio", "valRatio", "testRatio", "divideFnc", "trainFnc", "epochs", "max_fail", "min_grad", "mc", "lr","accuracy"];
varTypes = ["string","string","string","double","double","double","double","string","string","double","double","double","double","double","double"];
sz = [18 15];
results = table('Size',sz,'VariableTypes',varTypes,'VariableNames',varNames);
i = 1;
for outputTransferFcn_performFcn = 1:length(outputTransferFcns)
    outputTransferFcn = outputTransferFcns(outputTransferFcn_performFcn);
    performFcn = performFcns(outputTransferFcn_performFcn);
    for nHiddenUnits = [50, 200, 500]
        for train_val_test_ratio = 1:length(trainRatios)
            trainRatio = trainRatios(train_val_test_ratio);
            valRatio = valRatios(train_val_test_ratio);
            testRatio = testRatios(train_val_test_ratio);%             
            totalAccuracy = 0;
            for seed = [1, 2, 3]
                net = createNet(seed, nHiddenUnits, hiddenTransferFcn,...
                    outputTransferFcn, performFcn, trainRatio, valRatio, testRatio, divideFcn, trainFcn, epochs, max_fail,...
                    min_grad, mc, lr);
                [net,tr,Y,E] = train(net, transpose(data.X), encodedY);
                totalAccuracy = totalAccuracy + getAccuracy(Y(:,tr.testInd), encodedY(:,tr.testInd));
            end
            meanAccuracy = totalAccuracy/3;
            results(i, :) = {outputTransferFcn, hiddenTransferFcn, performFcn, nHiddenUnits, trainRatio, valRatio, testRatio, divideFcn, trainFcn, epochs, max_fail, min_grad, mc, lr, meanAccuracy }
            i = i + 1;
        end
            
    end
end
%table2latex(results, 'Latex_results.txt');


function oneHotEncoding = encodeOneHot(values)
    oneHotEncoding = zeros(length(values), 101);
    for i = 1:1:length(values)
        label = values(i);
        one = double([1:101] == label);
        oneHotEncoding(i, :) = one; 
    end
end

function accuracy = getAccuracy(labelsTrue, labelsPred)
    correct_outputs = 0;
    for r = 1:length(labelsPred)
        [~, output_label] = max(labelsPred(:, r));
        [~, test_label] = max(labelsTrue(:, r));
        if output_label == test_label
            correct_outputs = correct_outputs + 1;
        end
    end
    accuracy = correct_outputs/length(labelsPred);
end


function network = createNet(seed, nHiddenUnits, hiddenTransferFcn,...
    outputTransferFcn, performFcn, trainRatio, valRatio, testRatio, divideFcn, trainFcn,...
    epochs, max_fail, min_grad, mc, lr)

    rng(seed);
    % number of hidden units
    network = feedforwardnet([nHiddenUnits]);
    % transfer functions
    network.layers{1}.transferFcn = hiddenTransferFcn;
    network.layers{2}.transferFcn = outputTransferFcn;
    % cost function
    network.performFcn = performFcn;
    % percentage of train, valid, test
    network.divideFcn = divideFcn;
    network.divideParam.trainRatio = trainRatio;
    network.divideParam.valRatio = valRatio;
    network.divideParam.testRatio = testRatio;
    % train function
    network.trainFcn = trainFcn;
    % momentum
    if exist('mc', 'var')
        network.trainParam.mc = mc;
    end
    
    % learning rate
    if exist('lr', 'var')
        network.trainParam.lr = lr;
    end
    
    network.trainParam.max_fail = max_fail; % validation check parameter
    network.trainParam.epochs = epochs; % number of epochs parameter
    if exist('min_grad', 'var')
        network.trainParam.min_grad = min_grad; % minimum performance gradient
    end
    
    network.outputs{end}.processFcns = {};
    
            
    
end

