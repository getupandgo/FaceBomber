#include "faceBomber.h"

FaceBomber::FaceBomber() : faceDetector(dlib::get_frontal_face_detector()) {
    dlib::deserialize("/home/getupandgo/projects/FaceBomber/shape_predictor_model/shape_predictor_68_face_landmarks.dat") >> shapePredictor;
    getAllFacesForBombing();
}

void FaceBomber::doFaceBomb(const std::string imagePath) {
    dlib::load_image(targetImage, imagePath);

    pyramid_up(targetImage);

    auto faceShapes = extractFacePoses(targetImage);

    std::for_each(faceShapes.begin(), faceShapes.end(), [&](dlib::full_object_detection &faceShape) {
        std::cout << dlibObjectDetectionToCvPointsArray(faceShape) << std::endl;
    });

    dlib::image_window win;

    win.clear_overlay();
    win.set_image(targetImage);
    win.add_overlay(dlib::render_face_detections(faceShapes));

    std::cout << "Pause..." << std::endl;
    std::cin.get();
}

void FaceBomber::addFaceForBombing(const std::string faceName, const std::string imagePath) {
    // read image
    dlib::array2d<dlib::rgb_pixel> faceToExtract;
    dlib::load_image(faceToExtract, imagePath);

    auto facePoseOfDetectedFace = extractFacePoses(faceToExtract);

    if (facePoseOfDetectedFace.size() > 1) {
        std::cout << "too many faces detected; it must be only one \n aborting ..." << std::endl;
        throw "too many faces found";
    }


//    auto facePoints = dlibObjectDetectionToCvPointsArray(facePose);

//    std::vector<int> hullContourIndexes;
    // creating convexHull around facePoints obtained using dlib
//    cv::convexHull(facePoints, hullContourIndexes, false, false);
//    cv::convexHull(facePoints);

    bool faceExtracted = true;
    if (faceExtracted) {
        facesForBombing.insert(std::pair<std::string, std::string>(faceName, imagePath));
    } else {
        std::cout << "Unable to extract face from image" << std::endl;
    }


    // save image to "faces" folder

}

void FaceBomber::getAllFacesForBombing() {

}

std::vector<dlib::full_object_detection> FaceBomber::extractFacePoses(dlib::array2d<dlib::rgb_pixel> &targetImage) {
    // extract list of bounding boxes around all the faces
    std::vector<dlib::rectangle> detectedFaces = faceDetector(targetImage);
    std::cout << "Number of faces detected: " << detectedFaces.size() << std::endl;

    // Finding the pose of each detected face
    std::vector<dlib::full_object_detection> faceShapes;

    std::for_each(detectedFaces.begin(), detectedFaces.end(), [&](dlib::rectangle &face) {
        dlib::full_object_detection faceShape = shapePredictor(targetImage, face);
        faceShapes.push_back(faceShape);
    });

    return faceShapes;
}

cv::Point2i FaceBomber::fromDlibToCvPoint (const dlib::point &dlibPoint) {
    return cv::Point2i(dlibPoint.x(), dlibPoint.y());
};

std::vector<cv::Point2i> FaceBomber::dlibObjectDetectionToCvPointsArray (const dlib::full_object_detection &objDetection) {
    std::vector<cv::Point2i> cvPointsArray;
    size_t objDetectionPointsNumber = objDetection.num_parts();
    cvPointsArray.reserve(objDetectionPointsNumber);

    for(unsigned long i = 0; i < objDetectionPointsNumber; ++i) {
        dlib::point dlibPoint = objDetection.part(i);
        cvPointsArray.push_back(fromDlibToCvPoint(dlibPoint));
    }

    return cvPointsArray;
}
