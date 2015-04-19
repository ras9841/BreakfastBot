package com.example.allensanford.breakfastbot;


import android.app.Application;
import android.text.TextUtils;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.toolbox.Volley;

/**
 * Created by Allen Sanford on 4/19/2015.
 * BreakfastBot that implements the Simgleton Pattern
 */
public class BreakfastBot extends Application{

    /*
    Private Attributes
     */
    public static final String TAG = BreakfastBot.class.getSimpleName();
    private RequestQueue mRequestQueue;
    private static BreakfastBot mInstance;

    /*
    Methods
     */
    @Override
    public void onCreate() {
        super.onCreate();
        mInstance = this;
    }

    public static synchronized BreakfastBot getInstance() {
        return mInstance;
    }

    public RequestQueue getRequestQueue() {
        if (mRequestQueue == null) {
            mRequestQueue = Volley.newRequestQueue(getApplicationContext());
        }
        return mRequestQueue;
    }

    public void cancelPendingRequests(Object tag) {
        if (mRequestQueue != null) {
            mRequestQueue.cancelAll(tag);
        }
    }
    /*
    Generic Add Methods
     */
    public <T> void addToRequestQueue(Request<T> req, String tag) {
        // set the default tag if tag is empty
        req.setTag(TextUtils.isEmpty(tag) ? TAG : tag);
        getRequestQueue().add(req);
    }

    public <T> void addToRequestQueue(Request<T> req) {
        req.setTag(TAG);
        getRequestQueue().add(req);
    }
}
