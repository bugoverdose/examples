package example.bugoverdose.swagger.presentation;

import example.bugoverdose.swagger.domain.ProductRepository;
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

    private final ProductRepository productRepository;

    public ProductController(ProductRepository productRepository) {
        this.productRepository = productRepository;
    }

    @GetMapping
    public ResponseEntity<List<ProductResponse>> getAllProducts() {
        return ResponseEntity.ok(productRepository.findAll());
    }

    @GetMapping("/{productId}")
    public ResponseEntity<ProductResponse> getProduct(@PathVariable Long productId) {
        return ResponseEntity.ok(productRepository.find(productId));
    }

    @PostMapping
    public ResponseEntity<Void> createProduct(@RequestBody ProductRequest request) {
        Long productId = productRepository.save(request);
        URI uri = ServletUriComponentsBuilder
                .fromCurrentRequest()
                .path("/" + productId)
                .build().toUri();
        return ResponseEntity.created(uri).build();
    }

    @DeleteMapping("/{productId}")
    public ResponseEntity<Void> deleteProduct(@PathVariable Long productId) {
        productRepository.delete(productId);
        return ResponseEntity.noContent().build();
    }

    // @ControllerAdvice로 분리하여 구현하여도 동일 결과
    @ExceptionHandler
    public ResponseEntity<String> handleUnhandledException(RuntimeException e) {
        return ResponseEntity.internalServerError().body("서버에 문제가 발생하였습니다.");
    }

    @ExceptionHandler
    public ResponseEntity<String> handleUnhandledException(IllegalArgumentException e) {
        return ResponseEntity.badRequest().body(e.getMessage());
    }
}
