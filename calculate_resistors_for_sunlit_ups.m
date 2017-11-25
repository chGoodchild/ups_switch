disp("Hello World: Working with voltage dividers");

bR = 4670;          % Big resistor in Ohm
sR = 326;           % Small resistor in Ohm

max_output = 5;     % Maximum output voltage in volts.

max_input = max_output * (sR + bR) / sR;

disp("Maximum output voltage = ");
disp(max_output);
disp("Maximum input voltage = ");
disp(max_input);

resolution = 2^10;
disp("Resolution = ");
disp(resolution);

disp("Voltage resolution = ");
disp(max_input / resolution);

% 06 Volt: 05 - 7.5 Volts
voltage = 6;
lDev = 1;
uDev = 1.5;
disp("Battery voltage = ");
disp(voltage);

input = voltage - lDev;
output = input * (sR / (sR + bR));
disp("Lower bound output = ");
disp(output);

input = voltage + uDev;
output = input * (sR / (sR + bR));
disp("Upper bound output = ");
disp(output);



% 12 Volt: 10 - 15 Volts
voltage = voltage * 2;
lDev = lDev * 2;
uDev = uDev * 2;

disp("Battery voltage = ");
disp(voltage);

input = voltage - lDev;
output = input * (sR / (sR + bR));
disp("Lower bound output = ");
disp(output);

input = voltage + uDev;
output = input * (sR / (sR + bR));
disp("Upper bound output = ");
disp(output);


% 24 Volt: 20 - 30 Volts
voltage = voltage * 2;
lDev = lDev * 2;
uDev = uDev * 2;

disp("Battery voltage = ");
disp(voltage);

input = voltage - lDev;
output = input * (sR / (sR + bR));
disp("Lower bound output = ");
disp(output);

input = voltage + uDev;
output = input * (sR / (sR + bR));
disp("Upper bound output = ");
disp(output);


% 48 Volt: 40 - 60 Volts
voltage = voltage * 2;
lDev = lDev * 2;
uDev = uDev * 2;

disp("Battery voltage = ");
disp(voltage);

input = voltage - lDev;
output = input * (sR / (sR + bR));
disp("Lower bound output = ");
disp(output);

input = voltage + uDev;
output = input * (sR / (sR + bR));
disp("Upper bound output = ");
disp(output);



