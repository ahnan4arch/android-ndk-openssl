package com.example.openssltest;

import android.app.Activity;
import android.os.Bundle;
import android.util.Base64;
import android.widget.TextView;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        TextView tv = new TextView(this);
        byte[] afterHmac = hmacSha256("foo".getBytes());
        tv.setText(Base64.encodeToString(afterHmac, Base64.DEFAULT));
        setContentView(tv);
    }

    public native byte[] hmacSha256(byte[] data);

    static {
        System.loadLibrary("openssl-jni");
    }
}
