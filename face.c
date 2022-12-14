#include "face.h"

static PyObject *pName, *pModule, *ptrainFunc, *pprocimFunc, *ppredictFunc;
static PyObject *pemptyArgs, *pModel;
static PyObject *pProcIm;
static PyObject *ppredictArgs, *pPrediction;
static PyObject *pclasslab, *pdistance;
static wchar_t *pPath = L".";
static int classlabel;
static double preddistance;

void Face_initialize()
{
    Py_Initialize();
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append(\".\")");
    pName = PyUnicode_DecodeFSDefault("face"); //assign name of module
    pModule = PyImport_Import(pName); //import module
    printf("Our python module is imported...");
    ptrainFunc = PyObject_GetAttrString(pModule, PY_TRAIN_FUNC); //get training function
    pemptyArgs = PyTuple_New(0);
    pModel = PyObject_CallObject(ptrainFunc, pemptyArgs); //train eigenface model
    printf("Model is trained!\n");
    Py_DECREF(pName);
    return;
}

int Face_recognize()
{
    // Process image
    pprocimFunc = PyObject_GetAttrString(pModule, PY_PROCIM_FUNC);
    pProcIm = PyObject_CallObject(pprocimFunc, pemptyArgs);
    if(pProcIm == NULL){
        printf("ERROR: no image found\n");
        return 0;
    }
    printf("Image found\n");
    //Predict the class of the image
    ppredictFunc = PyObject_GetAttrString(pModule, PY_PREDICT_FUNC);
    ppredictArgs = PyTuple_Pack(2, pModel, pProcIm);
    pPrediction = PyObject_CallObject(ppredictFunc, ppredictArgs);
    if(pPrediction == NULL){
        printf("ERROR: prediction failed\n");
        return 0;
    }
    pclasslab = PyTuple_GET_ITEM(pPrediction, 0);
    pdistance = PyTuple_GET_ITEM(pPrediction, 1);
    classlabel = PyLong_AsLong(pclasslab);
    preddistance = PyFloat_AsDouble(pdistance);
    //printf("Class label: %li, with distance: %f\n", classlabel, preddistance);
    Py_DECREF(pemptyArgs); //De-reference stuff
    Py_DECREF(pProcIm);
    Py_DECREF(ppredictArgs);
    Py_DECREF(pPrediction);
    Py_DECREF(pclasslab);
    Py_DECREF(pdistance);
    if(preddistance < 3600){
        printf("Face recognized\n");
        return 1;
    }else{
        printf("Face not recognized");
        return 0;
    }
}

void Face_cleanup()
{
    if(pModule != NULL) Py_DECREF(pModule);
    if(ptrainFunc != NULL)Py_DECREF(ptrainFunc);
    if(pprocimFunc != NULL)Py_DECREF(pprocimFunc);
    if(ppredictFunc != NULL)Py_DECREF(ppredictFunc);
    if(pName != NULL)Py_DECREF(pName);
    Py_FinalizeEx();
    return;
}