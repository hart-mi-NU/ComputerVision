void toggleFilterMode(std::string *currentMode, std::string tobeMode);
int greyscale(cv::Mat &src, cv::Mat &dst);
int mainGrayscale(cv::Mat *src, cv::Mat *dest);
int blur5x5(cv::Mat &src, cv::Mat &dst);
int sobelX3x3(cv::Mat &src, cv::Mat &dst);
int sobelY3x3(cv::Mat &src, cv::Mat &dst);
int magnitude(cv::Mat &sx, cv::Mat &sy, cv::Mat &dst);
int blurQuantize(cv::Mat &src, cv::Mat &dst, int levels);
int cartoon(cv::Mat &src, cv::Mat &dst, int levels, int magThreshold);
int negative(cv::Mat &src, cv::Mat &dst);
// Extensions:
int smooth5x5(cv::Mat &src, cv::Mat &dst);
int colorMinimums(cv::Mat &src, cv::Mat &dst, uchar bMin, uchar gMin, uchar rMin);
int adjustBrightness(cv::Mat &src, cv::Mat &dst, int brightness);
int histogramEqualization(cv::Mat &src, cv::Mat &dst, int quantiles);