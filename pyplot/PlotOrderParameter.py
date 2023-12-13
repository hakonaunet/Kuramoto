import matplotlib.pyplot as plt

def plot_data(x, y, filename):
    print("Length of x:", len(x))
    print("Length of y:", len(y))
    plt.figure()  # Create a new figure
    plt.plot(x, y)
    plt.savefig(filename)
    plt.close()  # Close the figure to free up memory