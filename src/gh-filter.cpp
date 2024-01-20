#include <vector>
#include <utility>

using namespace std;

class gh_filter {
  private:
    vector<float> weights;
    float epoch;
    float scale_factor;

  public:
    gh_filter(vector<float> weights, float epoch = 1.0, float scale_factor = 4.0/10) {
      this->weights = weights;
      this->epoch = epoch;
      this->scale_factor = scale_factor;
    }

    pair<vector<float>, vector<float>> predict_using_gain_guess(float estimate, float gain_rate) {
      vector<float> estimates = vector<float>({estimate});
      vector<float> predictions = vector<float>();

      for (const float z : weights) {
        // generate prediction (derivative data, could be noisy)
        float prediction = estimate + gain_rate * epoch;
        gain_rate = gain_rate;

        // generate our estimate, update
        estimate = prediction + scale_factor * (z - prediction);
        
        // save
        estimates.push_back(estimate);
        predictions.push_back(prediction);
      }

      return make_pair(estimates, predictions);
    }
};

