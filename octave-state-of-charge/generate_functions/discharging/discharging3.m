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
########## Fit c40 ############
###############################

x = d3;
y = percent11;

maximum = 100;
minimum = -100;
increment = 1;
sw = 0;

a = minimum;
while (a < maximum)
  b = minimum;
  while (b < maximum)
    c = minimum;
    while (c < maximum)
      d = minimum;
      while (d < maximum)
        e = minimum;
        while (e < maximum)
          f = minimum;
          while (f < maximum)
            g = minimum;
            while (g < maximum)
              # SIXTH ORDER 2
              F = @(x, p) (x - p(1)).* (x - p(2)).* (x - p(3)).* (x - p(4)).* (x - p(5)).* (x - p(6)) + p(7);
              p = [a, b, c, d, e, f, g];
              
              g = g + increment;
              global verbose;
               verbose = 0;
               [data, fit] = leasqr(x, y, p, F);
              
              accumulator = 0;        
              for i = 1:x
                accumulator = accumulator + (y(i) - ((x(i) - fit(1, 1)).* (x(i) - fit(2, 1)).* (x(i) - fit(3, 1)).* (x(i) - fit(4, 1)).* (x(i) - fit(5, 1)).* (x(i) - fit(6, 1)) + fit(7, 1))).^2;
              endfor
              
              if (sw == 0)
                sw = 1;
                minimum = accumulator
                pfinal = p
              endif
                
              if (accumulator < minimum)
                minimum = accumulator
                pfinal = p
              endif
              
              endwhile
            f = f + increment;
            endwhile
          e = e + increment;
          endwhile
        d = d + increment;
        endwhile
      c = c + increment;
      endwhile
    b = b + increment;
    endwhile
  a = a + increment;
endwhile

global verbose;
 verbose = 0;
 [data, fit] = leasqr(x, y, pfinal, F);

figure(4)
hold on
grid on
box on
plot(x, y, 'b*', 'LineWidth', 1, 'MarkerSize', 7.5)

# SIXTH ORDER 
#plot(x,  (x - fit(1, 1)).* (x - fit(2, 1)).* (x - fit(3, 1)).* (x - fit(4, 1)).* (x - fit(5, 1)).* (x - fit(6, 1)) + fit(7, 1))
# Less precise
plot(x,  (x - 10.1354).* (x - 10.1681).* (x - 10.1423).* (x - 6.4437).* (x - 13.7005).* (x - 13.5256) + 27.9198)
 
fit