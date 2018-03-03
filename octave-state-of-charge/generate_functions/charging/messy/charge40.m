#pkg unload control 
pkg load optim


## Charge
c5 = [12.6, 12.77, 12.95, 13.2, 13.39, 13.53, 13.675, 14.02, 15.27, 15.96, 16.25, 16.38];
c10 = [12.38, 12.6, 12.82, 13.05, 13.2, 13.3, 13.41, 13.63, 14.08, 15.24, 15.72, 15.95];
c20 = [12.05, 12.42, 12.69, 12.89, 13.015, 13.12, 13.18, 13.3, 13.58, 14.15, 15.17, 15.54];
c40 = [11.8, 12.25, 12.55, 12.72, 12.82, 12.92, 12.95, 13.0, 13.15, 13.5, 14.5, 15.08];

## Rest
rest = [11.7, 11.915, 12.115, 12.24, 12.32, 12.415, 12.5, 12.6, 12.59, 12.61];

## Discharge
d100 = [12.66, 12.66, 12.64, 12.605, 12.54, 12.48, 12.38, 12.28, 12.12, 11.925, 11.7];
d20 = [12.604, 12.545, 12.54, 12.5, 12.42, 12.323, 12.22, 12.1, 11.915, 11.7, 11.45];
d10 = [12.485, 12.425, 12.35, 12.248, 12.13, 12.004, 11.88, 11.695, 11.48, 11.28, 11];
d5 = [12.065, 12.0, 11.917, 11.81, 11.69, 11.522, 11.385, 11.18, 10.91, 10.602, 10.2];
d3 = [11.78, 11.7, 11.61, 11.495, 11.325, 11.145, 10.98, 10.715, 10.39, 9.97, 9.48];

percent = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120];
percent11 = [110, 100, 90, 80, 70, 60, 50, 40, 30, 20, 10];
percentRest = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100];


###############################
########## Fit c5 #############
###############################
#leasqr()

x = c40;
y = percent;

# TWELFTH ORDER 
# F = @(x, p) p(1) * (x - p(2)).* (x - p(3)).* (x - p(4)).* (x - p(5)).* (x - p(6)).* (x - p(7)).* (x - p(8)).* (x - p(9)).* (x - p(10)).* (x - p(11)).* (x - p(12)).* (x - p(13)) + p(14);
# p = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
#p = fit

value = 0

# SIXTH ORDER 2
 F = @(x, p) (x - p(1)).* (x - p(2)).* (x - p(3)).* (x - p(4)).* (x - p(5)).* (x - p(6)) + p(7);
 p = [value, value, value, value, value, value, value]

# SIXTH ORDER 
# F = @(x, p) p(1) * (x - p(2)).* (x - p(3)).* (x - p(4)).* (x - p(5)).* (x - p(6)).* (x - p(7)) + p(8);
# p = [10, 10, 10, 10, 10, 10, 10, 10]
#p = fit

# FIFTH ORDER 
# F = @(x, p) p(1) * (x - p(2)).* (x - p(3)).* (x - p(4)).* (x - p(5)).* (x - p(6)) + p(7);
# p = [0, 26, -234, -3.7, -6.2, 154, -1217]

# SIGMOID
#F = @(x, p)(p(1) ./ (p(2) + exp(-x)));
#p = [1, 1]

# SEVENTH ORDER
#F = @(x, p) p(1) * x.^7 + p(2) * x.^6 + p(3) * x.^5 + p(4) * x.^4 + p(5) * x.^3 + p(6) * x.^2 + p(7) * x.^1;
#p = [1, 1, 1, 1, 1, 1, 1]

# SIXTH ORDER
#F = @(x, p) p(1) * x.^6 + p(2) * x.^5 + p(3) * x.^4 + p(4) * x.^3 + p(5) * x.^2 + p(6) * x.^1;
#p = [1, 1, 1, 1, 1, 1]

# FIFTH ORDER
#F = @(x, p) p(1) * x.^5 + p(2) * x.^4 + p(3) * x.^3 + p(4) * x.^2 + p(5) * x.^1;
#p = [1, 1, 1, 1, 1]

# FOURTH ORDER
#F = @(x, p) p(1) * x.^4 + p(2) * x.^3 + p(3) * x.^2 + p(4) * x.^1;
#p = [1, 1, 1, 1]

# FOURTH ORDER 8 VARIABLES
# F = @(x, p) p(1) * (x - p(2)).^4 + p(3) * (x - p(4)).^3 + p(5) * (x - p(6)).^2 + p(7) * (x - p(8)).^1;
# p = [1, 1, 1, 1, 1, 1, 1, 1]

# FOURTH ORDER 6 VARIABLES
# F = @(x, p) p(1) * (x - p(2)).^4 + p(3) * (x).^3 + p(4) * (x).^2 + p(5) * (x).^1 + p(6);
# p = [1, 1, 1, 1, 1, 1]

# FOURTH ORDER 6 VARIABLES method 2
# F = @(x, p) p(1) * (x - p(2)).* (x - p(3)).* (x - p(4)).* (x - p(5)) + p(6);
# p = [1, 1, 1, 1, 1, 1]

# THIRD ORDER
# F = @(x, p) p(1) * (x - p(2)).^3 + p(3) * (x - p(4)).^2 + p(5) * (x - p(6));
# p = [1, 1, 1, 1, 1, 1]

# SECOND ORDER
# F = @(x, p) p(1) * x.^2 + p(2) * x;
# p = [1, 1]

#global verbose;
# verbose = 1;
[data, fit] = leasqr(x, y, p, F);

figure(4)
hold on
grid on
box on
plot(x, y, 'b*', 'LineWidth', 1, 'MarkerSize', 7.5)


# SIXTH ORDER 
plot(x,  (x - fit(1, 1)).* (x - fit(2, 1)).* (x - fit(3, 1)).* (x - fit(4, 1)).* (x - fit(5, 1)).* (x - fit(6, 1)) + fit(7, 1))
# Low precision
#plot(x, (x - 14.387).* (x - 11.986).* (x - 14.326).* (x - 14.350).* (x - 17.222).* (x - 17.429) + 87.479)


# TWELFTH ORDER 
#plot(x,  fit(1, 1).* (x - fit(2, 1)).* (x - fit(3, 1)).* (x - fit(4, 1)).* (x - fit(5, 1)).* (x - fit(6, 1)).* (x - fit(7, 1)).* (x - fit(8, 1)).* (x - fit(9, 1)).* (x - fit(10, 1)).* (x - fit(11, 1)).* (x - fit(12, 1)).* (x - fit(13, 1)) + fit(14, 1))

# SIXTH ORDER 
#plot(x,  fit(1, 1).* (x - fit(2, 1)).* (x - fit(3, 1)).* (x - fit(4, 1)).* (x - fit(5, 1)).* (x - fit(6, 1)).* (x - fit(7, 1)) + fit(8, 1))
# Low precision
plot(x, 5.9324 * 10^(-03) .* (x - 9.9540 * 10^(+00)).* (x - 1.4976 * 10^(+01)).* (x - 1.4397 * 10^(+01)).* (x - 1.0765 * 10^(+01)).* (x + 5.8321 * 10^(+02)).* (x - 1.3623 * 10^(+01)) + 1.1195 * 10^(+02))


# FIFTH ORDER 
#plot(x,  fit(1, 1).* (x - fit(2, 1)).* (x - fit(3, 1)).* (x - fit(4, 1)).* (x - fit(5, 1)).* (x - fit(6, 1)) + fit(7, 1))

# SIGMOID
#plot(x, fit(1, 1) ./ (fit(2, 1) + exp(-x)));

# SEVENTH ORDER
# plot(x, fit(1, 1) * x.^7 + fit(2, 1) * x.^6 + fit(3, 1) * x.^5 + fit(4, 1) * x.^4 + fit(5, 1) * x.^3 + fit(6, 1) * x.^2 + fit(7, 1) * x.^1)
# Fifth order low precision
#plot(x, 3.0116*10^(-02) * x.^7 + -1.3049 * x.^6 + 1.4568*10^(1) * x.^5 + 9.3155 * x.^1 - 2.6359 * 10 * x.^3 + 1.2609*10^4 * x.^2 + 6.7309 * 100 * x.^1)

# SIXTH ORDER
# plot(x, fit(1, 1) * x.^6 + fit(2, 1) * x.^5 + fit(3, 1) * x.^4 + fit(4, 1) * x.^3 + fit(5, 1) * x.^2 + fit(6, 1) * x.^1)
# Fifth order low precision
# plot(x, 4.2724*10^(-02) * x.^5 + -2.1288 * x.^4 + 3.7995 * 10 * x.^3 + -2.7961 * 100 * x.^2 + 6.7309 * 100 * x.^1)

# FIFTH ORDER
#   plot(x, fit(1, 1) * x.^5 + fit(2, 1) * x.^4 + fit(3, 1) * x.^3 + fit(4, 1) * x.^2 + fit(5, 1) * x.^1)
# Fifth order low precision
# plot(x, 6.9747*10^(-02) * x.^5 + -3.9179 * x.^4 + 8.1383 * 10 * x.^3 + -7.3877 * 100 * x.^2 + 2.4699 * 1000 * x.^1)
   
# FOURTH ORDER
#plot(x, fit(1, 1) * x.^4 + fit(2, 1) * x.^3 + fit(3, 1) * x.^2 + fit(4, 1) * x.^1)
# Fourth order low precision
# plot(x, 0.25724 * x.^4 + -11.68739 * x.^3 + 177.39325 * x.^2 + -892.62972 * x.^1)

# FOURTH ORDER 8 VARIABLES
# plot(x, fit(1, 1) * (x - fit(2, 1)).^4 + fit(3, 1) * (x - fit(4, 1)).^3 + fit(5, 1) * (x - fit(6, 1)).^2 + fit(7, 1) * (x - fit(8, 1)).^1)
# Fourth order low precision
# plot(x, 0.25724 * x.^4 + -11.68739 * x.^3 + 177.39325 * x.^2 + -892.62972 * x.^1)

# FOURTH ORDER 6 VARIABLES
# plot(x, fit(1, 1) * (x - fit(2, 1)).^4 + fit(3, 1) * (x).^3 + fit(4, 1) * (x).^2 + fit(5, 1) * (x).^1 + fit(6, 1))
# Fourth order low precision
 
# FOURTH ORDER 6 VARIABLES method 2
#plot(x,  fit(1, 1).* (x - fit(2, 1)).* (x - fit(3, 1)).* (x - fit(4, 1)).* (x - fit(5, 1)) + fit(6, 1))
# Fourth order low precision
# plot(x, 0.25724 * x.^4 + -11.68739 * x.^3 + 177.39325 * x.^2 + -892.62972 * x.^1)

# THIRD ORDER
# plot(x, fit(1, 1) * x.^3 + fit(2, 1) * x.^2 + fit(3, 1) * x)

# THIRD ORDER
# plot(x, fit(1, 1) * (x - fit(2, 1)).^3 + fit(3, 1) * (x - fit(4, 1)).^2 + fit(5, 1) * (x - fit(6, 1)))

# SECOND ORDER
# plot(x, fit(1, 1) * x.^2 + fit(2, 1) * x.^1)
# Second order with reduced precision
# plot(x, 1.3226 * x.^2 + -14.2979 * x.^1)
