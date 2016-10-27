#ifndef FACEBOMBER_FACEBOMBER_H
#define FACEBOMBER_FACEBOMBER_H

#include <opencv2/opencv.hpp>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/image_io.h>
#include <iostream>
#include <fstream>

class FaceBomber {
public:
    FaceBomber();
    void doFancyFaceBomb(const std::string imagePath, const std::vector<std::string> newFacesPath);
    void doUglyFaceBomb(const std::string imagePath, const std::vector<std::string> newFacesPath);
    void addFaceForBombing(const std::string faceName, const std::string imagePath);
private:
    // methods:
    void getAllFacesForBombing();
    void replaceFace(std::vector<cv::Point2i> currentFaceShapes, std::vector<cv::Point2i> maskFaceShapes);
    std::vector<dlib::full_object_detection> findFacesAndExtractPoses(dlib::array2d<dlib::rgb_pixel> &targetImage);
    cv::Point2i fromDlibToCvPoint(const dlib::point &dlibPoint);
    std::vector<cv::Point2i> dlibObjectDetectionToCvPointsArray (const dlib::full_object_detection &objDetection);

    // fields:
    std::map <std::string, std::string> facesForBombing;
    dlib::frontal_face_detector faceDetector;       // Face detector to get bounding boxes for each face in an image.
    dlib::shape_predictor shapePredictor;       // Tool for prediction face landmark positions from face bounding box.
};

#endif //FACEBOMBER_FACEBOMBER_H
