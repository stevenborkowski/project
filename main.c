#define PY_SSIZE_T_CLEAN
#define PY_MODULE_NAME "/home/steven/cmpt433/work/project/face.py"
#define PY_TRAIN_FUNC "train_model"
#define PY_PROCIM_FUNC "process_input"
#define PY_PREDICT_FUNC "make_prediction"
#include <Python.h>

int main(){
    PyObject *pName, *pModule, *ptrainFunc, *pprocimFunc, *ppredictFunc;
    PyObject *pemptyArgs, *pModel;
    PyObject *pProcIm;
    PyObject *ppredictArgs, *pPrediction;
    PyObject *pclasslab, *pdistance;
    wchar_t *pPath = L".";
    int classlabel;
    double preddistance;

    Py_Initialize();
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append(\".\")");

    pName = PyUnicode_DecodeFSDefault("face");
    //printf("hello\n");
    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL) { //Train the model
        ptrainFunc = PyObject_GetAttrString(pModule, PY_TRAIN_FUNC);
        pemptyArgs = PyTuple_New(0);
        pModel = PyObject_CallObject(ptrainFunc, pemptyArgs);
    }

    if (pModule != NULL) { //Process an image
        pprocimFunc = PyObject_GetAttrString(pModule, PY_PROCIM_FUNC);
        pProcIm = PyObject_CallObject(pprocimFunc, pemptyArgs);
        if(pProcIm == NULL){
            printf("You done goofed\n");
            return 0;
        }
    }

    if (pModule != NULL) { //Predict the class of the image
        ppredictFunc = PyObject_GetAttrString(pModule, PY_PREDICT_FUNC);
        ppredictArgs = PyTuple_Pack(2, pModel, pProcIm);
        pPrediction = PyObject_CallObject(ppredictFunc, ppredictArgs);
        if(pPrediction == NULL){
            printf("You done goofed\n");
            return 0;
        }
        pclasslab = PyTuple_GET_ITEM(pPrediction, 0);
        pdistance = PyTuple_GET_ITEM(pPrediction, 1);
        classlabel = PyLong_AsLong(pclasslab);
        preddistance = PyFloat_AsDouble(pdistance);
        printf("Class label: %li, with distance: %f\n", classlabel, preddistance);

    }

    Py_FinalizeEx();

    return 0;
}