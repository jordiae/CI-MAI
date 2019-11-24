dataURL = 'https://people.cs.umass.edu/~marlin/data/caltech101_silhouettes_28.mat';
filename = 'caltech101_silhouettes_28.mat';
outfilename = websave(filename, dataURL);
data = load(outfilename);

columnMeans = mean(data.X, 1);
varMeans = var(data.X, 1);
normalizedX = transpose(normalize(double(data.X)));
encodedY = transpose(encodeOneHot(data.Y));
columnMeansNor = mean(data.X, 1);
varMeansNor = var(data.X, 1);

trainFcn= 'traingdx';
epochs = 1000;
max_fail = 6;
network.trainParam.min_grad = 1e-5;

hiddenTransferFcn = 'logsig';
divideFcn = 'dividerand';


bestAccuracyLrMc = 0;
bestLr;
bestMc;
for lr = [0.1 0.01 0.001] % default: 0.01
    for mc = [9 0.9 0.09] % default: 0.9
       net = createNet(seed, nHiddenUnits, hiddenTransferFcn,...
                    outputTransferFcn, performFcn, trainRatio, valRatio, testRatio, divideFcn, trainFcn, epochs, max_fail,...
                    max_fail, min_grad, mc, lr);
                %[net,tr,Y,E] = train(net, normalizedX, encodedY);
                [net,tr,Y,E] = train(net, transpose(data.X), encodedY);
                totalAccuracy = totalAccuracy + getAccuracy(Y(:,tr.testInd), encodedY(:,tr.testInd));
        
    end
end
return;
results = [];


for outputTransferFcn_performFcn = {{'logsig', 'mse'}; {'softmax', 'crossentropy'}}
    outputTransferFcn = outputTransferFcn_performFcn{1}{1};
    performFcn = outputTransferFcn_performFcn{1}{2};
    for nHiddenUnits = [50, 200, 500]
        for train_val_test_ratio = {[0.8, 0.1, 0.1]; [0.4, 0.2, 0.4]; [0.1, 0.1, 0.8]}
            trainRatio = train_val_test_ratio{1}(1);
            valRatio = train_val_test_ratio{1}(2);
            testRatio = train_val_test_ratio{1}(3);
            
            totalAccuracy = 0;
            for seed = [1, 2, 3]
                net = createNet(seed, nHiddenUnits, hiddenTransferFcn,...
                    outputTransferFcn, performFcn, trainRatio, valRatio, testRatio, divideFcn, trainFcn, epochs, max_fail,...
                    max_fail, min_grad, mc, lr);
                %[net,tr,Y,E] = train(net, normalizedX, encodedY);
                [net,tr,Y,E] = train(net, transpose(data.X), encodedY);
                totalAccuracy = totalAccuracy + getAccuracy(Y(:,tr.testInd), encodedY(:,tr.testInd));
            end
            meanAccuracy = totalAccuracy/3;
            
            
        end
            
    end
end

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
        [a, output_label] = max(labelsPred(:, r));
        [b, test_label] = max(labelsTrue(:, r));
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

