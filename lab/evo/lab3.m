FitnessFunction = @(x)(1-x(1))^2+100*(x(2)-x(1)^2)^2;

% Global parameters that we will not optimize
opts = gaoptimset('StallGenLimit', 50);
opts = gaoptimset(opts, 'FitnessScalingFcn', @fitscalingprop);

rng default % rng (random number generation) for reproducibility


% Values that we are going to experiment with
population_sizes = [10, 20, 50, 100];
n_generations = [15, 50, 150, 300];
initial_ranges = [5, 2, 1.5]; % 5 -> [-5 -5; 5 5]
selection_names = ["selectionstochunif", "selectionremainder", "selectionuniform", "selectionroulette", "selectiontournament"];
selection_funcs = {@selectionstochunif, @selectionremainder, @selectionuniform, @selectionroulette, @selectiontournament};
reproductions = 0:0.2:1;

% We are going to store all the results in a table
varNames = ["Population", "NGenerations", "InitialRange", "Selection", "Reproduction", "FVal"];
varTypes = ["double", "double", "double", "string", "double", "double"];
sz = [5*4*4*3*6 6];
results = table('Size', sz, 'VariableTypes', varTypes, 'VariableNames', varNames);

record_x = [];
record_y = [];
i = 0;
for p = 1:length(population_sizes)
    population_size = population_sizes(p);
    for g = 1:length(n_generations)
        n_generation = n_generations(g);
        for ir = 1:length(initial_ranges)
            initial_range = initial_ranges(ir);
            for s = 1:length(selection_funcs)
                selection_func = selection_funcs(s);
                selection_name = selection_names(s);
                for r = reproductions
                    i = i + 1;
                    reproduction = r;
                    opts = gaoptimset('StallGenLimit', 50);
                    opts = gaoptimset(opts, 'FitnessScalingFcn', @fitscalingprop);
                    opts = gaoptimset(opts, 'PopulationSize', population_size);
                    opts = gaoptimset(opts, 'Generations', n_generation);
                    opts = gaoptimset(opts, 'PopInitRange', [-initial_range -initial_range; initial_range initial_range]);
                    opts = gaoptimset(opts, 'SelectionFcn', selection_func);
                    opts = gaoptimset(opts, 'CrossoverFraction', reproduction);
                    rng default % rng (random number generation) for reproducibility
                    total = 0;
                    best_x = 0;
                    best_y = 0;
                    min_ = 99999999999;
                    for j = 1:3
                        [x, fval]=ga(FitnessFunction,2,[],[],[],[],[],[],[],opts);
                        total = total + fval;
                        if fval < min_
                            min_ = fval;
                            best_x = x(1);
                            best_y = x(2);
                        end
                        
                    end
                    record_x = [record_x; best_x];
                    record_y = [record_y; best_y];
                    avg = total/3;
                    results(i, :) = {population_size, n_generation, initial_range, selection_name, reproduction, avg};
                end
            end
        end
    end
end


T2 = results(:,S);
a = table2array(T2);
C = corr(a);
C_fval = C(:,5); % correlation between numeric variables and fval
scatter(a(:,4), a(:,5));
xlabel('Reproduction (crossover vs mutation ratio)')
ylabel('FVal')
[val, index] = min(a(:,5)); % val =0.0003479, index = 1255
results(index,:) % Population = 100, NGenerations = 50, InitialRange = 1.5, Selection =  "selectiontournament", Reproductiin = 0
record_x(index) % 0.9910
record_y(index) % 0.9818
save('results.mat','results','record_x', 'record_y');
