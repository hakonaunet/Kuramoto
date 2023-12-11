import matplotlib.pyplot as plt

def plot_data(x, y, filename):
    plt.plot(x, y)
    plt.savefig(filename)