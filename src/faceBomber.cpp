#include "faceBomber.h"

FaceBomber::FaceBomber(std::string imagePath) : faceDetector(dlib::get_frontal_face_detector()) {
    dlib::deserialize("../shape_predictor_model/shape_predictor_68_face_landmarks.dat") >> shapePredictor;

    dlib::load_image(targetImage, imagePath);

    pyramid_up(targetImage);
}

void FaceBomber::doFaceBomb() {
}

void FaceBomber::addFaceForBombing(std::string faceName, std::string imagePath) {
    // read image
    dlib::array2d<dlib::rgb_pixel> faceToExtract;
    dlib::load_image(faceToExtract, imagePath);

    // extract face ROI
    extractFace(faceToExtract); //assign somewhere

    // save image to "faces" folder

}

void FaceBomber::extractFace(dlib::array2d<dlib::rgb_pixel> targetImage) {
    // extract list of bounding boxes around all the faces
    std::vector<dlib::rectangle> detectedFaces = faceDetector(targetImage); // TODO
    std::cout << "Number of faces detected: " << detectedFaces.size() << std::endl;

    // Finding the pose of each detected face
    std::vector<dlib::full_object_detection> faceShapes;

    std::for_each(detectedFaces.begin(), detectedFaces.end(), [](dlib::full_object_detection &face) {
        dlib::full_object_detection faceShape = shapePredictor(targetImage, face);
        faceShapes.push_back(faceShape);
    });
}