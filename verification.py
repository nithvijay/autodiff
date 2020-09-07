import torch

def SimpleLinearRegression(epochs=1000, learning_rate=0.001):
    """
    Equivalent to the LinearRegression() method in main.cpp. This was used to verify results with PyTorch's autodiffrentiation system. This code was designed to imitate the C++ code as close as possible.
    """
    w = torch.tensor(0.0, requires_grad=True)
    b = torch.tensor(0.0, requires_grad=True)

    # to emulate implementation in C++
    x = [torch.tensor(temp) for temp in [1.0, 2.0, 3.0, 3.0, 4.0, 4.0, 6.0, 7.0, 8.0, 9.0]]
    y = [torch.tensor(temp) for temp in [10.0, 10.0, 10.0, 7.0, 6.0, 4.0, 5.0, 3.0, 2.0, 1.0]]
    m = len(x)

    def Linear(w, b, x):
        return w * x + b

    def get_MSE(pred, y):
        return (pred - y) ** 2
    
    # training loop
    for epoch in range(1, epochs+1):
        total_MSE = 0
        for i in range(m):

            pred = Linear(w, b, x[i])
            MSE = get_MSE(pred, y[i])

            MSE.backward()
            total_MSE += MSE.item()/m
            with torch.no_grad():
                w -= learning_rate * w.grad
                b -= learning_rate * b.grad

            w.grad.zero_()
            b.grad.zero_()

        if epoch == 1 or epoch % 200 == 0:
            print("Epoch {}\n\tMSE: {:.5f}\n\tParams: {:.5f}, {:.5f}".format(epoch, total_MSE, w, b))



SimpleLinearRegression()