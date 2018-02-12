x = randi([0, 1], 10, 8);

for i = 1:5
    % cross over
    x1 = x(:,1:4);
    x2 = x(:, 5:8);

    x1_dec = bi2de(x1);
    x2_dec = bi2de(x2);

    fitness = fitness_function(x1_dec, x2_dec);
    sorted_val = sort(fitness);
    max_1 = sorted_val(10);
    max_2 = sorted_val(9);

    for i = 1:10
        if fitness(i) == max_1
            i1 = i;
        elseif fitness(i) == max_2
            i2 = i;
        end
    end


    index = randi([1, 8]);
    save = x(i1, 1:index);
    x11 = horzcat( x(i1, 1:index) , x(i2, index+1: 8));
    x12 = horzcat( x(i2, 1:index) , x(i1, index+1: 8));

    x = vertcat(x, x11);
    x = vertcat(x, x12);

    % find lowest
    x1 = x(:,1:4);
    x2 = x(:, 5:8);

    x1_dec = bi2de(x1);
    x2_dec = bi2de(x2);

    fitness = fitness_function(x1_dec, x2_dec);
    sorted_val = sort(fitness);
    min_1 = sorted_val(2);
    min_2 = sorted_val(1);

    for i = 1:12
        if fitness(i) == min_1
            i1 = i;
        elseif fitness(i) == min_2
            i2 = i;
        end
    end

    m1 = min(min_1, min_2);
    m2 = max(min_1, min_2);

    x = vertcat( x(1:m2-1, :), x(m2+1: 12, :));
    x = vertcat( x(1:m1-1, :), x(m1+1: 11, :));

    % final fiteness calculation
    x1 = x(:,1:4);
    x2 = x(:, 5:8);

    x1_dec = bi2de(x1);
    x2_dec = bi2de(x2);

    fitness = fitness_function(x1_dec, x2_dec);
    a = max(fitness);
    b = mean(fitness);
    fprintf('max fitness is %f\n',a); 
    fprintf('avg fitness is %f\n',b); 
end

function z = fitness_function(x1, x2)
z = x1 + x2;
end


