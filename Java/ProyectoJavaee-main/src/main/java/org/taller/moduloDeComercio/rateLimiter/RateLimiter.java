package org.taller.moduloDeComercio.rateLimiter;

import java.util.concurrent.ConcurrentHashMap;

public class RateLimiter {
    private final ConcurrentHashMap<String, Long> requestTimes = new ConcurrentHashMap<>();
    private final long limitDurationMillis;

    public RateLimiter(long limitDurationMillis) {
        this.limitDurationMillis = limitDurationMillis;
    }

    public boolean allowRequest(String key) {
        long currentTime = System.currentTimeMillis();
        return requestTimes.compute(key, (k, lastTime) -> {
            if (lastTime == null || currentTime - lastTime > limitDurationMillis) {
                return currentTime;
            }
            return lastTime;
        }) == currentTime;
    }
}