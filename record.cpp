#include "opencv2/opencv.hpp"
#include <sys/socket.h> 
#include <arpa/inet.h>
#include <iostream>

using namespace cv;
using namespace std;

const int fps = 15;

int main(){
    
    VideoCapture cap;
    Mat frame;
    Mat flipped;
    
    if(!cap.open(0)){
        return 0;
    }
    int frame_width = cap.get(CAP_PROP_FRAME_WIDTH); 
    int frame_height = cap.get(CAP_PROP_FRAME_HEIGHT);
    Size frame_size(1067,600);
    VideoWriter video("output.avi",VideoWriter::fourcc('x','2','6','4'), 10, frame_size);
    
    while(cap.read(frame))
    {
        if(frame.empty()){
            break;
        }
        flip(frame,flipped,1);
        resize(flipped,frame,frame_size);
        
        imshow("Webcam", flipped);
        video.write(frame);
        if(waitKey(1000/fps) == 27){
            break;
            
        }
    }

    video.release();
    cap.release();
    
    destroyAllWindows();
    
    return 0;
}
