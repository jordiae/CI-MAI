FitnessFunction = @(x)(1-x(1))^2+100*(x(2)-x(1)^2)^2;


opts = gaoptimset(opts, 'StallGenLimit', 50);
opts = gaoptimset(opts, 'PopInitRange',[-2 -2; 2 2]);
opts = gaoptimset(opts, 'FitnessScalingFcn',@fitscalingprop);
rng default % rng (random number generation) for reprodurecord=[];


record=[];




population_sizes = [10, 20, 50, 100];
n_generations = [15, 50, 150, 300];
initial_ranges = [5, 2, 1.5]; % 5 -> [-5 -5; 5 5]
selections = ["selectionstochun", "selectionremainder", "selectionuniform", "selectionroulette", "selectiontournament"];
sel = [selectionroulette]
reproductions = 0:0.1:1; % de 0 a 1


varNames = ["Population", "generations", "initialRange", "selection", "reproduction"];
varTypes = ["double","double","double","string","double"];
sz = [5 5];
results_selection = table('Size',sz,'VariableTypes',varTypes,'VariableNames',varNames);

%% We will start by trying the selections (greedy). we can fix the other variable parameters to the
%% middle point of the values that we are going to test (with a bias towards the lowest one for computational
%% constraints), but with functions we cannot fix the "middle point"


population_size = 45;
n_generation = 100;
ir = 2;
reproduction = 0.5;
opts = gaoptimset(opts, 'PopulationSize', population_size);
opts = gaoptimset(opts, 'Generations', n_generation);
opts = gaoptimset(opts, 'PopInitRange', [-ir -ir; ir ir]);
opts = gaoptimset(opts, 'CrossoverFraction', reproduction);
table_i = 0;
for select_index = 1:length(n_generations)
    select_method = selections(select_index);
    display(select_method)
    opts = gaoptimset(opts, 'SelectionFcn', select_method);
    record=[];
    for rep=1:1:10
        rng default % rng (random number generation) for reprodurecord=[];
        [x, fval]=ga(FitnessFunction,2,[],[],[],[],[],[],[],opts);
        record = [record; fval];
    end
    results(table_i, :) = {population_size, n_generation, ir, select_method, reproduction}
    table_i = table_i + 1
end
% 
% for n=0:inter:1
%     opts = gaoptissssmset(opts,'CrossoverFraction',n);
%     [x, fval]=ga(FitnessFunction,2,[],[],[],[],[],[],[],opts);
%     
%     
% end
% reprodurecord = record;
% i = 0;
% for rep=1:1:20
%     rng default % rng (random number generation) for reprodurecord=[];
%     record=[];
%     for n=0:inter:1
%         opts = gaoptimset(opts,'CrossoverFraction',n);
%         opts = gaoptimset(opts,'PopulationSize',20);
%         opts = gaoptimset(opts,'Generations',150,'StallGenLimit', 100);
%         opts = gaoptimset(opts, 'SelectionFcn',@selectiontournament, 'FitnessScalingFcn',@fitscalingprop);
%         [x, fval]=ga(FitnessFunction,2,[],[],[],[],[],[],[],opts);
%         record = [record; fval];
%     end
%     reprodurecord = reprodurecord + record;
%     i = i + 1; 
% end
% avg_res = reprodurecord./i;
% plot(0:.01:1, avg_res);
% xlabel('Crossover Fraction');
% ylabel('fval')
