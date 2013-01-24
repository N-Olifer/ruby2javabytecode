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
        tNil,
        tInt,
        tObject,
        tUninitialized,
        tString,
        tArray
    }
    
    private CommonValue.Type fType;
    private int fIntValue;
    private String fStringValue;
    
    private CommonClass fObjectValue;
    
    private Array fArrayValue;
    
    public CommonValue() {
        fType = CommonValue.Type.tNil;
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
    
    public CommonValue(Array array) {
        fArrayValue = array;
        fType = CommonValue.Type.tArray;
    }
    
    public CommonValue add(CommonValue other) {
        if(fType == other.fType) {
            if(fType == Type.tInt) {
                CommonValue result = new CommonValue(fIntValue + other.fIntValue);
                return result;
            }
        }
        throw new RuntimeException("Incorrect types (Ruby)");
    }
    
    public CommonValue minus(CommonValue other) {
        if(fType == other.fType) {
            if(fType == Type.tInt) {
                CommonValue result = new CommonValue(fIntValue - other.fIntValue);
                return result;
            }
        } 
        throw new RuntimeException("Incorrect types (Ruby)");
    }
    
    public CommonValue div(CommonValue other) {
        if(fType == other.fType) {
            if(fType == Type.tInt) {
                CommonValue result = new CommonValue(fIntValue / other.fIntValue);
                return result;
            }
        }
        throw new RuntimeException("Incorrect types (Ruby)");
    }
    
    public CommonValue mul(CommonValue other) {
        if(fType == other.fType) {
            if(fType == Type.tInt) {
                CommonValue result = new CommonValue(fIntValue * other.fIntValue);
                return result;
            }
        }
        throw new RuntimeException("Incorrect types (Ruby)");
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
            case tNil:
                fObjectValue = null;
                fType = Type.tNil;
                break;
            case tUninitialized:
                break;
            case tArray:
                fArrayValue = newValue.fArrayValue;
                fType = Type.tArray;
                break;
        }
        return this;
    }
    
    public CommonValue less(CommonValue other) {
        if(fType == other.fType) {
            if(fType == Type.tInt) {
                CommonValue result;
                if(fIntValue < other.fIntValue)
                    result = new CommonValue(1);
                else
                    result = new CommonValue(0);
                return result;
            }
        }
        throw new RuntimeException("Incorrect types (Ruby)");
    }
    
    public CommonValue more(CommonValue other) {
        if(fType == other.fType) {
            if(fType == Type.tInt) {
                CommonValue result;
                if(fIntValue > other.fIntValue)
                    result = new CommonValue(1);
                else
                    result = new CommonValue(0);
                return result;
            }
        }
        throw new RuntimeException("Incorrect types (Ruby)");
    }
    public boolean getBoolean()
    {
        if(fType == Type.tInt) {
            return fIntValue != 0 ? true : false;
        }
        return false;
    }
    public CommonValue equ(CommonValue other) {
        if(fType == other.fType) {
            if(fType == Type.tInt) {
                CommonValue result;
                if(fIntValue == other.fIntValue)
                    result = new CommonValue(1);
                else
                    result = new CommonValue(0);
                return result;
            }
        }
        throw new RuntimeException("Incorrect types (Ruby)");
    }
    
    public CommonValue or(CommonValue other) {
        if(fType == other.fType) {
            if(fType == Type.tInt) {
                CommonValue result;
                if(getBoolean() || other.getBoolean())
                    result = new CommonValue(1);
                else
                    result = new CommonValue(0);
                return result;
            }
        }
        throw new RuntimeException("Incorrect types (Ruby)");
    }
    
    public CommonValue and(CommonValue other) {
        if(fType == other.fType) {
            if(fType == Type.tInt) {
                CommonValue result;
                if(getBoolean() && other.getBoolean())
                    result = new CommonValue(1);
                else
                    result = new CommonValue(0);
                return result;
            }
        }
        throw new RuntimeException("Incorrect types (Ruby)");
    }
    
    public CommonValue not() {
        return new CommonValue(getBoolean() ? 0 : 1);
    }
    
    public CommonValue nequ(CommonValue other) {
        if(fType == other.fType) {
            if(fType == Type.tInt) {
                CommonValue result;
                if(fIntValue != other.fIntValue)
                    result = new CommonValue(1);
                else
                    result = new CommonValue(0);
                return result;
            }
        }
        throw new RuntimeException("Incorrect types (Ruby)");
    }
    
    public CommonValue uMinus() {
        if(fType == Type.tInt) {
            CommonValue result = new CommonValue(-fIntValue);
            return result;
        }
        throw new RuntimeException("Incorrect types (Ruby)");
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
   
    public Array getArray() {
        return fArrayValue;
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
            case tArray:
                System.out.print("-array-");
                break;
        }   
    }

    @Override
    public String toString() {
        switch(fType) {
            case tInt:
                return String.valueOf(fIntValue);
            case tString:
                return fStringValue;
            case tObject:
                return fObjectValue.toString();
            case tUninitialized:
                return "Uninitialized";
            case tArray:
                return fArrayValue.toString(); //TODO красивая печать для массива
        } 
        return super.toString();
    }
    
    
}
