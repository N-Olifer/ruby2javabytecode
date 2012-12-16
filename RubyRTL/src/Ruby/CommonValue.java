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
    
    public CommonValue(CommonClass object) {
        fObjectValue = object;
        fType = CommonValue.Type.tObject;
    }
    
    public CommonValue add(CommonValue other) {
        if(fType == other.fType) {
            if(fType == Type.tInt) {
                CommonValue result = new CommonValue(fIntValue + other.fIntValue);
                return result;
            }
        }
        else
        {
            System.out.print("aaa");
            printType();
            other.printType();
        }
        return null;
    }
    
    public CommonValue minus(CommonValue other) {
        if(fType == other.fType) {
            if(fType == Type.tInt) {
                CommonValue result = new CommonValue(fIntValue - other.fIntValue);
                return result;
            }
        }
        return null;
    }
    
    public CommonValue div(CommonValue other) {
        if(fType == other.fType) {
            if(fType == Type.tInt) {
                CommonValue result = new CommonValue(fIntValue / other.fIntValue);
                return result;
            }
        }
        return null;
    }
    
    public CommonValue mul(CommonValue other) {
        if(fType == other.fType) {
            if(fType == Type.tInt) {
                CommonValue result = new CommonValue(fIntValue * other.fIntValue);
                return result;
            }
        }
        return null;
    }
    
    public CommonValue assign(CommonValue newValue) {
        switch(newValue.fType) {
            case tInt:
                fIntValue = newValue.fIntValue;
                fType = Type.tInt;
                break;
            case tString:
                fStringValue = newValue.fStringValue;
                fType = Type.tString;
                break;
            case tObject:
                fObjectValue = newValue.fObjectValue;
                fType = Type.tObject;
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
    
    public void printType() {
        switch(fType) {
            case tInt:
                System.out.print("-int-");
                break;
            case tString:
                System.out.print("-str-");
                break;
            case tObject:
                System.out.print("-obj-");
                break;
            case tUninitialized:
                System.out.print("-uninit-");
                break;
        }
    }
}
