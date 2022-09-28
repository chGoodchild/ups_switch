import matplotlib
import matplotlib.pyplot as plt
from scipy.optimize import least_squares
import numpy as np

## Charge
c5 = [12.6, 12.77, 12.95, 13.2, 13.39, 13.53, 13.675, 14.02, 15.27, 15.96, 16.25, 16.38]
c10 = [12.38, 12.6, 12.82, 13.05, 13.2, 13.3, 13.41, 13.63, 14.08, 15.24, 15.72, 15.95]
c20 = [12.05, 12.42, 12.69, 12.89, 13.015, 13.12, 13.18, 13.3, 13.58, 14.15, 15.17, 15.54]
c40 = [11.8, 12.25, 12.55, 12.72, 12.82, 12.92, 12.95, 13.0, 13.15, 13.5, 14.5, 15.08]

## Rest
rest = [11.7, 11.915, 12.115, 12.24, 12.32, 12.415, 12.5, 12.6, 12.59, 12.61]

## Discharge
d100 = [12.66, 12.66, 12.64, 12.605, 12.54, 12.48, 12.38, 12.28, 12.12, 11.925, 11.7]
d20 = [12.604, 12.545, 12.54, 12.5, 12.42, 12.323, 12.22, 12.1, 11.915, 11.7, 11.45]
d10 = [12.485, 12.425, 12.35, 12.248, 12.13, 12.004, 11.88, 11.695, 11.48, 11.28, 11]
d5 = [12.065, 12.0, 11.917, 11.81, 11.69, 11.522, 11.385, 11.18, 10.91, 10.602, 10.2]
d3 = [11.78, 11.7, 11.61, 11.495, 11.325, 11.145, 10.98, 10.715, 10.39, 9.97, 9.48]


def get_fit(x, y, order):
    lst = []
    for pwr in np.arange(order + 1)[::-1]:
        if pwr == 0:
            lst.append(np.ones(len(x)))
        elif pwr == 1:
            lst.append(x)
        else:
            lst.append(np.array([xn ** pwr for xn in x]))

    A = np.vstack(lst).T
    y = y[:, np.newaxis]
    alpha = np.dot((np.dot(np.linalg.inv(np.dot(A.T, A)), A.T)), y)
    return alpha


def sigmoid(x, steepness, xoffs, yoffs):
    nx = x - xoffs
    return (nx - steepness*nx) / (steepness - 2 * steepness * np.abs(nx) + 1) + yoffs


def get_sigmoid_fit(x, y, order, offs, steepness):
    neworder = 0
    lst = []
    for pwr in np.arange(order)[::-1]:
        if pwr == 0:
            lst.append(np.ones(len(x)))
            neworder += 1
        else:
            lst.append(sigmoid(x, steepness=steepness, xoffs=offs[0], yoffs=offs[1]))
            neworder += 1

    A = np.vstack(lst).T
    y = y[:, np.newaxis]
    print(A)
    print(y)
    alpha = np.dot((np.dot(np.linalg.inv(np.dot(A.T, A)), A.T)), y)
    return alpha, neworder


def get_poly_sigmoid_fit(x, y, order, offs, steepness):
    neworder = 0
    lst = []
    lst.append(sigmoid(x, steepness=steepness, xoffs=offs[0], yoffs=offs[1]))
    neworder += 1

    for pwr in np.arange(order)[::-1]:
        if pwr == 0:
            lst.append(np.ones(len(x)))
            neworder += 1
        elif pwr == 1:
            lst.append(x)
        else:
            lst.append(np.array([xn ** pwr for xn in x]))
            neworder += 1

    A = np.vstack(lst).T
    y = y[:, np.newaxis]
    print(A)
    print(y)
    alpha = np.dot((np.dot(np.linalg.inv(np.dot(A.T, A)), A.T)), y)
    return alpha, neworder


def plot(x, y, order, lbl):
    alpha = get_fit(x, np.array(y), order)
    xnew = np.linspace(9, 17, 100)

    ynew = 0
    for index, pow in zip(np.arange(order + 1), np.arange(order + 1)[::-1]):
        print("index: ", index, ", pow: ", pow + 1)
        ynew += alpha[index] * xnew ** pow + 1

    for i in np.arange(len(ynew)):
        if ynew[i] < -10:
            ynew[i] = -10
        if ynew[i] > 130:
            ynew[i] = 130

    plt.plot(xnew, ynew, label=lbl)


def plot_sigmoid(x, y, order, lbl, offs, steepness):
    alpha, neworder = get_sigmoid_fit(np.array(x), np.array(y), order, offs, steepness=steepness)
    xnew = np.linspace(9, 17, 100)

    ynew = 0
    for index, pow in zip(np.arange(neworder), np.arange(neworder)[::-1]):
        if pow < 1:
            ynew += alpha[index] * xnew ** pow + 1
        else:
            ynew += alpha[index] * sigmoid(np.array(xnew), steepness=steepness, xoffs=offs[0], yoffs=offs[1])

    for i in np.arange(len(ynew)):
        if ynew[i] < -10:
            ynew[i] = -10
        if ynew[i] > 130:
            ynew[i] = 130
        if xnew[i] < 12:
            ynew[i] = -10

    plt.plot(xnew, ynew, label=lbl)


def plot_poly_sigmoid(x, y, order, lbl, offs, steepness):
    alpha, neworder = get_poly_sigmoid_fit(np.array(x), np.array(y), order, offs, steepness=steepness)
    xnew = np.linspace(9, 17, 100)

    # TODO: Introduce sigmoid...

    ynew = 0
    ynew += alpha[0] * sigmoid(np.array(xnew), steepness=steepness, xoffs=offs[0], yoffs=offs[1])

    alpha = alpha[1:]
    for index, pow in zip(np.arange(neworder), np.arange(neworder)[::-1]):
        ynew += alpha[index] * xnew ** pow + 1

    for i in np.arange(len(ynew)):
        if ynew[i] < -10:
            ynew[i] = -10
        if ynew[i] > 130:
            ynew[i] = 130
        if xnew[i] < 12:
            ynew[i] = -10

    plt.plot(xnew, ynew, label=lbl)


percent = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120]
percent11 = [110, 100, 90, 80, 70, 60, 50, 40, 30, 20, 10]
percentRest = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]

plt.scatter(c5, percent, label="C5")
plot(x=c5, y=percent, order=3, lbl="C5 3rd order")

plt.scatter(c10, percent, label="C10")
# plot(x=c10, y=percent, order=3, lbl="C10 3rd order") # Not as good
plot_poly_sigmoid(x=c10, y=percent, order=2, lbl="C10 sigmoid", offs=(15, 100), steepness=0.13)

plt.scatter(c20, percent, label="C20")
#plot(x=c20, y=percent, order=2, lbl="C20 2nd order") # Not as good
plot_sigmoid(x=c20, y=percent, order=2, lbl="C20 sigmoid", offs=(15, 100), steepness=0.11)
# plot_poly_sigmoid(x=c20, y=percent, order=4, lbl="C20 poly sigmoid", offs=(15, 100), steepness=0.11) # Not as good

plt.scatter(c40, percent, label="C40")

# plot_poly_sigmoid(x=c40, y=percent, order=4, lbl="C40 poly sigmoid", offs=(16, 100), steepness=0.13) # Not as good
# plot_poly_sigmoid(x=c40, y=percent, order=4, lbl="C40 poly sigmoid", offs=(13, 100), steepness=0.14) # Not as good
plot_poly_sigmoid(x=c40, y=percent, order=4, lbl="C40 poly sigmoid", offs=(15, 100), steepness=0.17)




plt.xlabel("Voltage in V")
plt.ylabel("State of Charge in %")
plt.legend(loc="upper left")
# plt.savefig("charge.pdf")
plt.show()

plt.scatter(rest, percentRest, label="rest")

plt.scatter(d3, percent11, label="D3")
plt.scatter(d5, percent11, label="D5")
plt.scatter(d10, percent11, label="D10")
plt.scatter(d100, percent11, label="D100")
plt.xlabel("Voltage in V")
plt.ylabel("State of Charge in %")
plt.legend(loc="upper left")
plt.savefig("discharge.pdf")