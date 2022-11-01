# project
**Setup**  
```  
pip install opencv-contrib-python  
pip install numpy  
```  
**face.py**  
Contains function *train_model()* that trains and returns an eigneface model.  
Also contains a script to test the model.
  
**training-data**  
This directory contains the AT&T facedatabase, as well as additional pictures added to train the model.  
  
All pictures input into the model for training and predicting must be 92x112, grayscale, .pgm files.  
