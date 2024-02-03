package example.bugoverdose.swagger.dto;

public class ProductResponse {
    private final Long id;
    private final String name;
    private final Integer price;

    public ProductResponse(Long id, String name, Integer price) {
        this.id = id;
        this.name = name;
        this.price = price;
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