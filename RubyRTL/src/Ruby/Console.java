/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Ruby;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author astr0lit
 */
public class Console {
    static public CommonValue printInt(CommonValue arg) {
        System.out.print(arg.getInt());
        return arg;
    }
    static public CommonValue print(CommonValue arg) {
        System.out.print(arg.toString());
        return arg;
    }
    static public CommonValue println(CommonValue arg) {
        System.out.println(arg.toString());
        return arg;
    }
    static public CommonValue gets() throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        String result = input.readLine();
        int intResult;
        try {
            intResult = Integer.parseInt(result);
        } catch(NumberFormatException ex) {
            return new CommonValue(result);
        }
        return new CommonValue(intResult);
    }
}
