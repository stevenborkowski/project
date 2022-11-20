import cv2
import os
import numpy as np
PATH = "training-data/s"

def train_model():

    test_label = []
    for x in range(41):
        test_label.append(x+1)
    

    imagelist = []
    labellist = []
    filename = ''
    fullname = ''

    print("Loading data...")
    for val in test_label:
        filename = PATH + "{0}/".format(val)
        for x in range(1,11):
            fullname = filename + "{0}".format(x) + ".pgm"
            myimage = cv2.imread(fullname)
            gray = cv2.cvtColor(myimage, cv2.COLOR_BGR2GRAY)
            imagelist.append(gray)
            labellist.append((val))
    print("Total faces: {im}, Total labels: {lb}".format(im=len(imagelist),lb=int(len(labellist)/10)))
    model = cv2.face.EigenFaceRecognizer_create()
    model.train(imagelist,np.array(labellist))
    print("Eigenface model is trained")
    return model
#need function that a) resizes and converts to .pgm gray input pictures
def process_input():
    inputim = cv2.imread("test3.pgm") # need to figure out how and where rpi places pics
    # need to crop out face from image
    gray = cv2.cvtColor(inputim, cv2.COLOR_BGR2GRAY)
    processed = cv2.resize(gray, [92,112])
    print("Image is processed")
    return processed

def make_prediction(mymodel, myimage): # THIS FUNCTION IS MAINLY FOR THE MILESTONE
    predicted = mymodel.predict(myimage)
    # filename = PATH + "{0}/".format(predicted[0])
    # fullname = filename + "1" + ".pgm"
    # ogimage = cv2.imread(fullname)
    # oggray = cv2.cvtColor(ogimage, cv2.COLOR_BGR2GRAY)
    # cv2.resize(myimage, (1472, 1792))
    # cv2.resize(oggray, (1472, 1792))
    # combined = np.concatenate((myimage, oggray), axis = 1)
    # cv2.putText(combined,
    #             "Test image predicted",
    #             (1, 80),
    #             cv2.FONT_HERSHEY_PLAIN,
    #             1,
    #             (0,0,0),
    #             1)
    # cv2.putText(combined,
    #             "class",
    #             (120, 93),
    #             cv2.FONT_HERSHEY_PLAIN,
    #             1,
    #             (0,0,0),
    #             1)
    # cv2.imwrite("output.jpg",combined)
    # print(predicted)
    # cv2.imshow('image', combined)
    # cv2.waitKey(0)
    # cv2.destroyAllWindows()
    print(predicted)
    return predicted

#mymodel = train_model()
#myimage = process_input("test3.pgm") #"training-data/s31/2.pgm"
#make_prediction(mymodel, myimage)