package com.valuecommerce.android.cocosIF;

import android.app.Activity;
import android.util.Log;
import android.view.ViewGroup;
import android.widget.FrameLayout;

import com.adpresso.android.AdRequestNotifier;
import com.adpresso.android.AdpressoInterstitialAd;
import com.adpresso.android.AdpressoView;
import com.adpresso.android.InterstitialAdListener;

import org.cocos2dx.lib.Cocos2dxActivity;

/**
 * Created by mitakahashi on 2016/12/09.
 */

public class AdpressoInterstitialAdModule {
    private static ViewGroup rootView = null;
    private static AdpressoView adView = null;
    private static InterstitialAdListener listener;

    public static void createAdpressoInterstitialAd(final String publisherId,final float x, final float y) {
        final Activity activity = (Activity) Cocos2dxActivity.getContext();

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
                AdpressoInterstitialAd interstitialAd = new AdpressoInterstitialAd(rootView.getContext(),publisherId);
                listener = new InterstitialAdListener() {
                    @Override
                    public void onPresentScreen(AdRequestNotifier adRequestNotifier) {

                    }

                    @Override
                    public void onDismissScreen(AdRequestNotifier adRequestNotifier) {

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
                interstitialAd.addRequestListener(listener);
                interstitialAd.show();
            }
        });



    }
    public static void createAdpressoInterstitialAd(final String publisherId) {
        createAdpressoInterstitialAd(publisherId,0,0);
    }
}
