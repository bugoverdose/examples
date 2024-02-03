package example.bugoverdose.swagger.presentation;

import example.bugoverdose.swagger.dto.ProductRequest;
import example.bugoverdose.swagger.dto.ProductResponse;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.servlet.support.ServletUriComponentsBuilder;

import java.net.URI;
import java.util.List;

@RestController
@RequestMapping("/api/products")
public class ProductController {

    @GetMapping
    public ResponseEntity<List<ProductResponse>> getAllProducts() {
        List<ProductResponse> products = List.of(
                new ProductResponse(1L, "고구마", 1500),
                new ProductResponse(2L, "감자", 1000),
                new ProductResponse(3L, "양배추", 2000));
        return ResponseEntity.ok(products); // statusCode 200
    }

    @GetMapping("/{productId}")
    public ResponseEntity<ProductResponse> getProduct(@PathVariable Long productId) {
        ProductResponse dummyProduct = new ProductResponse(productId, "고구마", 1500);
        return ResponseEntity.ok(dummyProduct); // statusCode 200
    }

    @PostMapping
    public ResponseEntity<Void> createProduct(@RequestBody ProductRequest request) {
        URI uri = ServletUriComponentsBuilder.fromCurrentRequest()
                .path("/" + 4)
                .build().toUri(); // Location : /api/products/4
        return ResponseEntity.created(uri).build(); // statusCode 201
    }

    @DeleteMapping("/{productId}")
    public ResponseEntity<Void> deleteProduct(@PathVariable Long productId) {
        return ResponseEntity.noContent().build(); // statusCode 204
    }
}
