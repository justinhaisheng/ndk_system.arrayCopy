package com.aispeech.array;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.widget.TextView;

import com.aispeech.array.javautil.HashMap;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    public static class Student{
        String name;

        public Student(String name){
            this.name = name;
        }

        // 很少复写 equals
        @Override
        public int hashCode() {
            return name.hashCode();
        }

        @Override
        public boolean equals(Object obj) {
            if(obj instanceof Student){
                Student stu = (Student) obj;
                return name.equals(stu.name);
            }
            return false;
        }
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());

        int number = 0x0001 & 1234567;
        Log.d("MainActivity","number:"+number);
        String a = "luhaisheng";
        String b = "luhaisheng";

        HashMap<Integer,Student> map = new HashMap<>();

        for(int i=0;i<30;i++){
            map.push(i, new Student("lu："+i));
        }


        for(int i=0;i<30;i++){
            Log.d("MainActivity",map.get(i).name);
        }


        Log.d("MainActivity","a==b:"+(a==b)+" a.equals(b)"+a.equals(b));
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}
