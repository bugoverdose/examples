package example.bugoverdose.swagger.dto;

import example.bugoverdose.swagger.domain.Product;

public class ProductResponse {
    private final Long id;
    private final String name;
    private final Integer price;

    private ProductResponse(Long id, String name, Integer price) {
        this.id = id;
        this.name = name;
        this.price = price;
    }

    public static ProductResponse of(Product product) {
        return new ProductResponse(product.getId(), product.getName(), product.getPrice());
    }

    public Long getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public Integer getPrice() {
        return price;
    }
}