package Ruby;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author ZerG
 */
public class CommonValue {
    
    private enum Type {
        tInt,
        tObject,
        tUninitialized
    }
    
    private CommonValue.Type fType;
    private int fIntValue;
    
    private CommonClass fObjectValue;
    
    public CommonValue() {
        fType = CommonValue.Type.tUninitialized;
    }
    
    public CommonValue(int intValue) {
        fIntValue = intValue;
        fType = CommonValue.Type.tInt;
    }
    
    public CommonValue add(CommonValue other) {
        if(fType == other.fType) {
            if(fType == CommonValue.Type.tInt) {
                CommonValue result = new CommonValue(fIntValue + other.fIntValue);
                return result;
            }
        }
        return null;
    }
    
    public void assign(CommonValue newValue) {
        //if(fType == newValue.fType) {
            if(newValue.fType == CommonValue.Type.tInt) {
                fIntValue = newValue.fIntValue;
            }
    }
    
    public int getInt() {
        return fIntValue;
    }
    
    public CommonClass getObject() {
        return fObjectValue;
    }
}
