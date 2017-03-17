package com.valuecommerce.android.cocosIF;

import android.app.Activity;
import android.graphics.Point;
import android.view.ViewGroup;
import android.widget.FrameLayout;
import android.widget.LinearLayout;

import com.adpresso.android.AdRequestNotifier;
import com.adpresso.android.AdpressoIconAdSet;
import com.adpresso.android.AdpressoIconView;
import com.adpresso.android.IconAdListener;

import org.cocos2dx.lib.Cocos2dxActivity;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by mitakahashi on 2016/12/09.
 */

public class AdpressoIconAdModule {
    private static ViewGroup rootView = null;
    private static AdpressoIconAdSet iconAdSet = null;
    private static IconAdListener listener;
    private static List<AdpressoIconView> views = null;
    private static Point point;


    public static void createAdpressoIconAd(final String publisherId,final float x, final float y) {
        final Activity activity = (Activity) Cocos2dxActivity.getContext();

        int local_x = (int)x;
        int local_y = (int)y;
        point = new Point();
        point.set(local_x,local_y);
        listener = new IconAdListener() {
            @Override
            public void onReceiveAd(AdRequestNotifier adRequestNotifier, int i) {

            }

            @Override
            public void onReceiveAd(AdRequestNotifier adRequestNotifier) {

            }

            @Override
            public void onFailedToReceiveAd(AdRequestNotifier adRequestNotifier) {

            }

            @Override
            public void onTouchAd(AdRequestNotifier adRequestNotifier) {

            }
        };
        activity.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                if (null == rootView){
                    rootView = new FrameLayout(activity);
                }
                if (null == rootView.getParent()){
                    activity.addContentView(rootView,new ViewGroup.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT));
                }
                if (views != null){
                    hideAdpressoIconAd();
                    views = new ArrayList<AdpressoIconView>();
                }else {
                    views = new ArrayList<AdpressoIconView>();
                }
                iconAdSet = new AdpressoIconAdSet(activity,publisherId);

                iconAdSet.addRequestListener(listener);
                AdpressoIconView iconView1 = new AdpressoIconView(rootView.getContext());
                AdpressoIconView iconView2 = new AdpressoIconView(rootView.getContext());
                LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(
                        LinearLayout.LayoutParams.MATCH_PARENT,
                        LinearLayout.LayoutParams.MATCH_PARENT);
                iconView1.setLayoutParams(new LinearLayout.LayoutParams(
                        AdpressoIconView.getIconWidth(rootView.getContext()),
                        AdpressoIconView.getIconHeight(rootView.getContext())));
                iconView2.setLayoutParams(params);
                views.add(iconView1);
                views.add(iconView2);

                for (AdpressoIconView view : views){
                    iconAdSet.add(view);
                    rootView.addView(view);

                }
                iconAdSet.load();
            }
        });


    }
    public static void createAdpressoIconAd(final String publisherId) {
        createAdpressoIconAd(publisherId,0,0);
    }

    public static void hideAdpressoIconAd(){
        final Activity activity = (Activity) Cocos2dxActivity.getContext();

        activity.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                for (AdpressoIconView view : views){
                    rootView.removeView(view);
                }
                iconAdSet.removeAll();
                iconAdSet = null;
                views = null;
            }
        });





    }

}
