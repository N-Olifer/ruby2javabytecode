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
       // return array.indexOf(value);
    }
    
    public CommonValue get(CommonValue index) {
        return array.get(index.getInt());
    }
    
    public CommonValue set(CommonValue index, CommonValue value) {
        array.set(index.getInt(), value);
        return value;
    }
}