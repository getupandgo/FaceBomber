#ifndef FACESWAPPER_FACESWAPPER_H
#define FACESWAPPER_FACESWAPPER_H

#include <opencv2/opencv.hpp>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing.h>
#include <dlib/image_io.h>
#include <iostream>
#include <fstream>

class FaceSwapper {
public:
    FaceSwapper(std::string imagePath);
    void swap();
private:
    dlib::array2d<dlib::rgb_pixel> targetImage;
    // Face detector to get bounding boxes for each face in an image.
    dlib::frontal_face_detector faceDetector;
    // Tool for prediction face landmark positions from face bounding box.
    dlib::shape_predictor shapePredictor;
};

#endif //FACESWAPPER_FACESWAPPER_H
