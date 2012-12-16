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
    static public void printString(String arg) {
        System.out.print(arg);
    }
}
