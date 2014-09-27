<?php
class ClientStreamWrapper extends DrupalLocalStreamWrapper {
  /**
   * Implements abstract public function getDirectoryPath()
   */
  public function getDirectoryPath() {
    return variable_get('client_path', conf_path() . '/files');
  }

  function getExternalUrl() {
    $path = str_replace('\\', '/', $this->getTarget());
    $path1 = explode('/', $path);

    if ($path1[0] === 'styles') {
      array_shift($path1);
      $path = 'system/files/styles/' . implode('/', $path1);
    }
    else {
      $path = 'system/client/' . $path;
    }

    return url($path, array('absolute' => TRUE));
  }
}

class RemoteStreamWrapper {

  function setUri($uri) {
    $this->uri = $uri;
  }

  function getUri() {
    return $this->uri;
  }

  protected function getTarget($uri = NULL) {
    if (!isset($uri)) {
      $uri = $this->uri;
    }

    list($scheme, $target) = explode('://', $uri, 2);

    // Remove erroneous leading or trailing, forward-slashes and backslashes.
    return trim($target, '\/');
  }

  function getExternalUrl() {
    $path = str_replace('\\', '/', $this->getTarget());
    $path1 = explode('/', $path);
    //dpm($path);
    if ($path1[0] === 'styles') {
      array_shift($path1);
      $path = variable_get('client_remote') . '/files/styles/' . implode('/', $path1);
    }
    else {
      $path = variable_get('client_remote') . '/files/' . $path;
    }

    return url($path, array('absolute' => TRUE));
  }
}