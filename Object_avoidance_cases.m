%Fake arduino code

%input distances
left_side_d = input('distance from left side sensor: ');
left_corner_d = input('distance from left corner sensor: ');
front_d = input('distance from front sensor: ');
right_corner_d = input('distance from right corner sensor: ');
right_side_d = input('distance from right side sensor: ');

%create distance matrix
distances = [left_side_d left_corner_d front_d right_corner_d right_side_d];

%find number of sensors
sensor_count = length(distance);

%trigger distance
trigger_dist = input('what is the closest you wanna get to an object? ');

%create boolean matrix of zeros
object_boolean = zeros(sensor_count);

for i = 1:1:sensor_count
    if distances(i) <= trigger_dist
        object_boolean(i) = 1;
    end
end

%define object case matricies in boolean terms
left_wall = [1 0 0 0 0];
left_corner_1 = [1 1 1 0 0];
left_corner_2 = [1 1 0 0 0];
left_corner_3 = [1 0 1 0 0];
left_corner_4 = [0 1 1 0 0];
front_wall = [0 0 1 0 0];
front_corner = [0 1 0 1 0];
right_corner_1 = [0 0 1 1 1];
right_corner_2 = [0 0 0 1 1];
right_corner_3 = [0 0 1 0 1];
right_corner_4 = [0 0 1 1 0];
right_wall = [0 0 0 0 1];

case_matrix = [left_wall;
    left_corner_1;
    left_corner_2;
    left_corner_3;
    left_corner_4;
    front_wall;
    front_corner;
    right_corner_1;
    right_corner_2;
    right_corner_3;
    right_corner_4;
    right_wall;];

%determine which case you're in
test_variable = 0;
i = 0;
while test_variable == 0
    i = i+1;
    if case_matrix(i,:) == object_boolean
        test_variable = 1;
    end
end

    
    


