#ifndef TEST_H
#define TEST_H
#include <vector>
#include <string>

namespace testSpace {
    using namespace std;
    typedef int value_t;
    typedef float precision_t;
    typedef vector<value_t> labels_t;
    typedef vector<precision_t> weights_t;
    typedef vector<vector<value_t>> samples_t;
    class Test {
    protected:
        samples_t samples = samples_t();
        labels_t labels = labels_t();
        weights_t weights = weights_t();
    public:
        Test();
        void fit(samples_t&, labels_t&, weights_t&);
        ~Test();
        void print();
        static inline string version() { return "0.1.0"; }
    };
}
#endif

