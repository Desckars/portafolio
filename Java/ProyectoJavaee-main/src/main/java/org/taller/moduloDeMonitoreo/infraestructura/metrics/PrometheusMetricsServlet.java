/*
package org.taller.moduloDeMonitoreo.infraestructura.metrics;

import io.micrometer.prometheus.PrometheusConfig;
import io.micrometer.prometheus.PrometheusMeterRegistry;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/metrics")
public class PrometheusMetricsServlet extends HttpServlet {
    private static final PrometheusMeterRegistry registry =
            new PrometheusMeterRegistry(PrometheusConfig.DEFAULT);

    public static PrometheusMeterRegistry getRegistry() {
        return registry;
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        resp.setContentType("text/plain");
        resp.getWriter().write(registry.scrape());
    }
}
*/