/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Ruby;

/**
 *
 * @author astr0lit
 */
public class Console {
    static public CommonValue printInt(CommonValue arg) {
        System.out.print(arg.getInt());
        return arg;
    }
    static public String printString(CommonValue arg) {
        System.out.print(arg.toString());
        return arg.getString();
    }
}
