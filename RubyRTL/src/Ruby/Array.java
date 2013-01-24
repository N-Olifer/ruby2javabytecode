/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Ruby;

import java.util.ArrayList;

/**
 *
 * @author astr0lit
 */
public class Array {
    
    private ArrayList<CommonValue> array;
    
    public Array()
    {
       array = new ArrayList<>();
    }
    
    public void append(CommonValue value) {
        array.add(value);
    }
    
    public CommonValue get(CommonValue index) {
        int i = index.getInt();
        if(i < 0) {
            i = array.size() + i;
        }
        return array.get(i);
    }
    
    public CommonValue set(CommonValue index, CommonValue value) {
        array.set(index.getInt(), value);
        return value;
    }

    @Override
    public String toString() {
        String result = new String();
        result += "[ ";
        for(CommonValue element : array) {
            result += element.toString();
            result += " ";
        }
        result += "]";
        return result;
    }
    
    
}