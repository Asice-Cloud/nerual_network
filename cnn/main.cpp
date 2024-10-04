#include "ANN.h"
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);

  Network network({
      new FullyConnectedLayer(1, 100),
      new ActivationLayer(new Sigmoid),
      new FullyConnectedLayer(100, 100),
      new ActivationLayer(new Sigmoid),
      new FullyConnectedLayer(100, 1),
  });

  auto poly = [](double x) {
    return 5 * pow(x, 3) + 2 * pow(x, 2) - 7 * x + 1;
  };
  auto [train_input, train_output] = load_polynomial(1000, poly, -2, 2);
  network.train(train_input, train_output, new MeanSquaredError, 100, 0.01);

  for (int x = -2; x <= 2; x += 1) {
    Matrix input = make_matrix({{1.0 * x}});
    Matrix output = network.predict(input);
    double predict = output(0, 0);
    double actual = poly(x);
    std::cout << "x: " << std::fixed << std::setprecision(2) << std::setw(2)
              << std::right << x << " Predict: " << std::fixed
              << std::setprecision(2) << std::setw(7) << predict
              << " Actual: " << std::fixed << std::setprecision(2)
              << std::setw(7) << actual << " Error: " << std::fixed
              << std::setprecision(2) << std::setw(7) << predict - actual
              << std::endl;
  }
  return 0;
}
