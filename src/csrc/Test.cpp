# include "Test.h"
# include <iostream>

namespace testSpace {
    Test::Test() = default;
    Test::~Test() = default;
    void Test::fit(samples_t& samples, labels_t& labels, weights_t& weights)
    {
        this->labels = labels;
        this->weights = weights;
        this->samples = samples;
    }
    void Test::print()
    {
        cout << "Labels: ";
        for (auto item : labels) {
            cout << item << ", ";
        }
        cout << "end." << endl;
        cout << "Weights: ";
        for (auto item : weights) {
            cout << item << ", ";
        }
        cout << "end." << endl;
        cout << "Samples: ";
        for (auto item : samples) {
            cout << "[";
            for (auto item2 : item) {
                cout << item2 << ", ";
            }
            cout << "], ";
        }
    }
}