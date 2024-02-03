package example.bugoverdose.swagger.domain;

public class Product {
    private final Long id;
    private final String name;
    private final Integer price;

    public Product(Long id, String name, Integer price) {
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
