/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Ruby;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Hashtable;

/**
 *
 * @author astr0lit
 */
public class Array {
    
    //private ArrayList<CommonValue> array;
    private HashMap<CommonValue,CommonValue>array;
    int elemensCount;
    public Array()
    {
       array = new HashMap<>();
       elemensCount = 0;
    }
    
    public void append(CommonValue value) {
        array.put(new CommonValue(elemensCount++), value);
    }
    
    public CommonValue get(CommonValue key) {
        System.out.println("Count: " + String.valueOf(array.size()) + "\n" + "Key:" + key.toString());
        return array.containsKey(key) ? array.get(key) : new CommonValue();
    }
    
    public CommonValue set(CommonValue key, CommonValue value) {
        array.put(key, value);
        System.out.println("Count: " + String.valueOf(array.size()) + "\n" + "Key:" + key.toString() + " Value: " + value.toString());
        return value;
    }

    @Override
    public String toString() {
        String result = new String();
        result += "[ ";
        for(CommonValue element : array.keySet()) {
            //result += element.toString();
            //result += ":";
            result += array.get(element);
            result += " ";
        }
        result += " ]";
        return result;
    }
    
    
}