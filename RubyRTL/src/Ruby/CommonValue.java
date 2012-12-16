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
        tUninitialized,
        tString
    }
    
    private CommonValue.Type fType;
    private int fIntValue;
    private String fStringValue;
    
    private CommonClass fObjectValue;
    
    public CommonValue() {
        fType = CommonValue.Type.tUninitialized;
    }
    
    public CommonValue(int intValue) {
        fIntValue = intValue;
        fType = CommonValue.Type.tInt;
    }
    
    public CommonValue(String StringValue) {
        fStringValue = StringValue;
        fType = CommonValue.Type.tString;
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
    
    public CommonValue assign(CommonValue newValue) {
            if(newValue.fType == CommonValue.Type.tInt) {
                fIntValue = newValue.fIntValue;
            }
            switch(newValue.fType) {
                case tInt:
                    fIntValue = newValue.fIntValue;
                    break;
                case tString:
                    fStringValue = newValue.fStringValue;
                    break;
                case tObject:
                    fObjectValue = newValue.fObjectValue;
                    break;
                case tUninitialized:
                    break;
            }
            return this;
    }
    
    public int getInt() {
        return fIntValue;
    }

    public String getString() {
        return fStringValue;
    }
    
    public CommonClass getObject() {
        return fObjectValue;
    }
    
}
