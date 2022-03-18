#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>
#include <chrono>
using namespace std::chrono;

using namespace cv;
using namespace std;

int main(){
    //Read image
    Mat image = imread("/content/padp-self-study/modified-cuda-GaussianBlur/Images/Pikachu.jpg",IMREAD_GRAYSCALE);

    //check if image exits
    if(image.empty()){
        cout<<"can not find image"<<endl;
        return 0;
    }
    Mat result1, result2;

    //Apply gaussian filter with kernel size 5
    auto start = high_resolution_clock::now();
    GaussianBlur(image, result1, Size(7, 7), 0, 0);
    auto stop = high_resolution_clock::now();
    //Apply gaussian filter with kernel size 20
    //GaussianBlur(image, result2, Size(15, 15), 0, 0);

    //Create windows to display images
    // namedWindow("image", WINDOW_NORMAL);
    // namedWindow("result1", WINDOW_NORMAL);
    // namedWindow("result2", WINDOW_NORMAL);

    // //display images
    // imshow("image", image);
    // imshow("result1", result1);
    // imshow("result2", result2);

    //press esc to exit the program
   // waitKey(0);

    imwrite("out_seq.jpg",result1);
    //close all the opened windows
   // destroyAllWindows();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << (double)duration.count()/1000 << endl;

    return 0;
}