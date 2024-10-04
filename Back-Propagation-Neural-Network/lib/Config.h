#pragma once

using std::size_t;

namespace Config {
    const size_t INNODE = 20;
    const size_t HIDENODE = 30;
    const size_t OUTNODE = 1;

    const double lr = 0.8;
    const double threshold = 1e-4;
    const size_t max_epoch = 3*1e5;
}
