package com.valuecommerce.android.cocosIF;

import android.app.Activity;
import android.content.Context;
import android.view.ViewGroup;
import android.widget.FrameLayout;

import com.adpresso.android.AdpressoView;

import org.cocos2dx.lib.Cocos2dxActivity;

/**
 * Created by mitakahashi on 2016/12/07.
 */

public class AdpressoAdModule {
    private static ViewGroup rootView = null;
    private static AdpressoView adView = null;

    public static void createAdpressoAd(final String publisherId,final float x, final float y) {
        final Activity activity = (Activity)Cocos2dxActivity.getContext();

        activity.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                if (null == rootView){
                    rootView = new FrameLayout(activity);
                }
                if (null == rootView.getParent()){
                    activity.addContentView(rootView,new ViewGroup.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT));
                }
                if (adView != null){
                    rootView.removeView(adView);
                }
                adView = new AdpressoView(activity);
                adView.setPublisherID(publisherId);
                rootView.addView(adView);
            }
        });
    }
    public static void hideAdpressoAd(){
        final Activity activity = (Activity)Cocos2dxActivity.getContext();

        activity.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                rootView.removeView(adView);
            }
        });

    }
}
