//
// Created by ChrisKim on 2023/6/8.
//

#include "LoadPlane.h"

std::pair<std::vector<Matrix>, std::vector<Matrix>> circle_type(int size) {
    // random generator
    auto now = std::chrono::system_clock::now();
    auto now_sec = std::chrono::time_point_cast<std::chrono::seconds>(now);
    auto timestamp = now_sec.time_since_epoch().count();
    std::default_random_engine generator(timestamp);
    std::normal_distribution<double> distribution(0, 1);

    std::vector<Matrix> input, output;

    // inner circle
    for (int i = 0; i < size / 2; i++) {
        double degree = 2.0 * i / size * 2 * M_PI;
        double x = cos(degree) + 0.5 * distribution(generator);
        double y = sin(degree) + 0.5 * distribution(generator);
        input.push_back(make_matrix({{x}, {y}}));
        output.push_back(make_matrix({{1}}));
    }

    // outer ring
    for (int i = 0; i < size / 2; i++) {
        double degree = 2.0 * i / size * 2 * M_PI;
        double x = 4 * cos(degree) + 0.5 * distribution(generator);
        double y = 4 * sin(degree) + 0.5 * distribution(generator);
        input.push_back(make_matrix({{x}, {y}}));
        output.push_back(make_matrix({{-1}}));
    }
    return {input, output};
}

std::pair<std::vector<Matrix>, std::vector<Matrix>> cluster_type(int size) {
    // random generator
    auto now = std::chrono::system_clock::now();
    auto now_sec = std::chrono::time_point_cast<std::chrono::seconds>(now);
    auto timestamp = now_sec.time_since_epoch().count();
    std::default_random_engine generator(timestamp);
    std::normal_distribution<double> distribution(0, 1);

    std::vector<Matrix> input, output;

    // cluster 1
    for (int i = 0; i < size / 2; i++) {
        double x = distribution(generator);
        double y = distribution(generator);
        input.push_back(make_matrix({{x}, {y}}));
        output.push_back(make_matrix({{1}}));
    }

    // cluster 2
    for (int i = 0; i < size / 2; i++) {
        double x = 4 + distribution(generator);
        double y = 4 + distribution(generator);
        input.push_back(make_matrix({{x}, {y}}));
        output.push_back(make_matrix({{-1}}));
    }

    return {input, output};
}

std::pair<std::vector<Matrix>, std::vector<Matrix>> window_type(int size) {
    // random generator
    auto now = std::chrono::system_clock::now();
    auto now_sec = std::chrono::time_point_cast<std::chrono::seconds>(now);
    auto timestamp = now_sec.time_since_epoch().count();
    std::default_random_engine generator(timestamp);
    std::uniform_real_distribution<double> distribution(-1, 1);

    std::vector<Matrix> input, output;

    for (int i = 0; i < size; i++) {
        double x = distribution(generator);
        double y = distribution(generator);
        input.push_back(make_matrix({{x}, {y}}));
        output.push_back(make_matrix({{x * y >= 0 ? 1.0 : -1.0}}));
    }

    return {input, output};
}

std::pair<std::vector<Matrix>, std::vector<Matrix>> whirlpool_type(int size) {
    // random generator
    auto now = std::chrono::system_clock::now();
    auto now_sec = std::chrono::time_point_cast<std::chrono::seconds>(now);
    auto timestamp = now_sec.time_since_epoch().count();
    std::default_random_engine generator(timestamp);
    std::normal_distribution<double> distribution(0, 0.4);

    std::vector<Matrix> input, output;

    // type 1
    for (int i = 0; i < size / 2; i++) {
        double degree = 4.0 * i / size * 2 * M_PI;
        double x = degree * cos(degree) + distribution(generator);
        double y = degree * sin(degree) + distribution(generator);
        input.push_back(make_matrix({{x}, {y}}));
        output.push_back(make_matrix({{1}}));
    }

    // type -1
    for (int i = 0; i < size / 2; i++) {
        double degree = 4.0 * i / size * 2 * M_PI;
        double x = degree * cos(degree + 2 * M_PI) + distribution(generator);
        double y = degree * sin(degree + 2 * M_PI) + distribution(generator);
        input.push_back(make_matrix({{-x}, {-y}}));
        output.push_back(make_matrix({{-1}}));
    }

    return {input, output};
}

std::pair<std::vector<Matrix>, std::vector<Matrix>> load_plane(int size, const std::string &type) {
    if (type == "circle") {
        return circle_type(size);
    } else if (type == "cluster") {
        return cluster_type(size);
    } else if (type == "window") {
        return window_type(size);
    } else if (type == "whirlpool") {
        return whirlpool_type(size);
    } else {
        std::cerr << "Error: unknown type" << std::endl;
        exit(1);
    }
}
