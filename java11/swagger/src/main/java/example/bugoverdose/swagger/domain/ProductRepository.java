package example.bugoverdose.swagger.domain;

import example.bugoverdose.swagger.dto.ProductRequest;
import example.bugoverdose.swagger.dto.ProductResponse;
import org.springframework.stereotype.Repository;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

@Repository
public class ProductRepository {

    private final Map<Long, Product> database;
    private Long id;

    public ProductRepository() {
        this.database = new HashMap<>();
        database.put(1L, new Product(1L, "고구마", 1500));
        database.put(2L, new Product(2L, "감자", 1000));
        database.put(3L, new Product(3L, "양배추", 2000));
        this.id = 3L;
    }

    public List<ProductResponse> findAll() {
        return database.values()
                .stream()
                .map(ProductResponse::of)
                .collect(Collectors.toUnmodifiableList());
    }

    public ProductResponse find(Long productId) {
        if (!database.containsKey(productId)) {
            throw new IllegalArgumentException("존재하지 않는 상품입니다.");
        }
        return ProductResponse.of(database.get(productId));
    }

    public Long save(ProductRequest request) {
        Long newId = getAutoIncrementedId();
        Product product = new Product(newId, request.getName(), request.getPrice());
        database.put(newId, product);
        return newId;
    }

    public void delete(Long productId) {
        database.remove(productId);
    }

    private Long getAutoIncrementedId() {
        return ++id;
    }
}
