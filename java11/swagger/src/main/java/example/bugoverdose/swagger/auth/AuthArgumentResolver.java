package example.bugoverdose.swagger.auth;

import javax.servlet.http.HttpServletRequest;

import org.springframework.core.MethodParameter;
import org.springframework.web.bind.support.WebDataBinderFactory;
import org.springframework.web.context.request.NativeWebRequest;
import org.springframework.web.method.support.HandlerMethodArgumentResolver;
import org.springframework.web.method.support.ModelAndViewContainer;

public class AuthArgumentResolver implements HandlerMethodArgumentResolver {

    // 매개변수에 @AuthUserId 어노테이션이 붙어있을 때
    @Override
    public boolean supportsParameter(MethodParameter parameter) {
        return parameter.hasParameterAnnotation(AuthUserId.class);
    }

    // 해당 매개변수의 인자로 아래 로직의 반환값을 넣어준다
    @Override
    public Object resolveArgument(MethodParameter parameter,
                                  ModelAndViewContainer mavContainer,
                                  NativeWebRequest webRequest,
                                  WebDataBinderFactory binderFactory) {
        return 1L; // 요청 메시지에 담긴 정보를 활용하여 가공된 정보 (ex. JWT 토큰을 통해 알아낸 유저의 id 등)
    }
}