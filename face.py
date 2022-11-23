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

    #print("Loading data...")
    for val in test_label:
        filename = PATH + "{0}/".format(val)
        for x in range(1,11):
            fullname = filename + "{0}".format(x) + ".pgm"
            myimage = cv2.imread(fullname)
            gray = cv2.cvtColor(myimage, cv2.COLOR_BGR2GRAY)
            imagelist.append(gray)
            labellist.append((val))
    #print("Total faces: {im}, Total labels: {lb}".format(im=len(imagelist),lb=int(len(labellist)/10)))
    model = cv2.face.EigenFaceRecognizer_create()
    model.train(imagelist,np.array(labellist))
    #print("Eigenface model is trained")
    return model

def process_input():
    inputim = cv2.imread("test3.pgm") # need to figure out how and where rpi places pics
    # need to crop out face from image
    gray = cv2.cvtColor(inputim, cv2.COLOR_BGR2GRAY)
    processed = cv2.resize(gray, [92,112])
    #print("Image is processed")
    return processed

def make_prediction(mymodel, myimage):
    predicted = mymodel.predict(myimage)
    print(predicted)
    return predicted

#mymodel = train_model()
#myimage = process_input() #"training-data/s31/2.pgm" #"test3.pgm"
#make_prediction(mymodel, myimage)